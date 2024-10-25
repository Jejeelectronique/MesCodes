X²#ifndef LiquidCrystal_h
#define LiquidCrystal_h

#include <Arduino.h>

class LiquidCrystal {
  public:
    LiquidCrystal(int rs, int enable, int d4, int d5, int d6, int d7);
    void begin(int cols, int rows);
    void clear();
    void home();
    void setCursor(int col, int row);
    void print(const char* string);
  private:
    void sendCommand(int value);
    void sendData(int value);
    void pulseEnable();
    int _rs_pin;
    int _enable_pin;
    int _data_pins[4];
};

#endif


