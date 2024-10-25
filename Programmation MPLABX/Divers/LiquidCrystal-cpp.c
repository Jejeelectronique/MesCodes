#include "LiquidCrystal.h"

LiquidCrystal::LiquidCrystal(int rs, int enable, int d4, int d5, int d6, int d7) {
  _rs_pin = rs;
  _enable_pin = enable;
  _data_pins[0] = d4;
  _data_pins[1] = d5;
  _data_pins[2] = d6;
  _data_pins[3] = d7;
}

void LiquidCrystal::begin(int cols, int rows) {
  pinMode(_rs_pin, OUTPUT);
  pinMode(_enable_pin, OUTPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(_data_pins[i], OUTPUT);
  }

  sendCommand(0x33);
  sendCommand(0x32);
  sendCommand(0x28);
  sendCommand(0x0C);
  sendCommand(0x06);
  sendCommand(0x01);

  if (cols > 16) {
    cols = 16;
  }
  if (rows > 2) {
    rows = 2;
  }

  sendCommand(0x80);
  for (int i = 0; i < cols; i++) {
    sendData(' ');
  }

  for (int i = 0; i < rows-1; i++) {
    sendCommand(0xC0 + i * 0x40);
    for (int j = 0; j < cols; j++) {
      sendData(' ');
    }
  }
}

void LiquidCrystal::clear() {
  sendCommand(0x01);
}

void LiquidCrystal::home() {
  sendCommand(0x02);
}

void LiquidCrystal::setCursor(int col, int row) {
  int row_offsets[] = { 0x00, 0x40, 0x14, 0x54 };
  if ( row > 2 ) {
    row = 2;
  }
  sendCommand(0x80 | (col + row_offsets[row]));
}

void LiquidCrystal::print(const char* string) {
  while (*string) {
    sendData(*string++);
  }
}

void LiquidCrystal::sendCommand(int value) {
  digitalWrite(_rs_pin, LOW);
  for (int i = 0; i < 4; i++) {
    digitalWrite(_data_pins[i], (value >> (4*i)) & 0x0F
