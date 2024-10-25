
#include "Wire.h"
#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C LCD(0x27, 20, 2);

int level = 1;
int pause = 400;
byte p = 0;

byte dragon[8] = {
 0b01110, 0b11011, 0b11111, 0b11100, 0b11111, 0b01100, 0b10010, 0b11011
};
byte arbre[8] = {
 0b00000, 0b00000, 0b00000, 0b11011, 0b11011, 0b11011, 0b01100, 0b01100
};
byte pierre[8] = {
 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b01110, 0b11111
};
byte oiseau[8] = {
 0b00100, 0b00101, 0b01111, 0b11111, 0b10100, 0b00100, 0b00000, 0b00000
};

void setup() {
 pinMode (10, OUTPUT);
 pinMode (A1, INPUT);
 analogWrite(A1, LOW);
 LCD.init();
 LCD.backlight();

 LCD.createChar(0, dragon);
 LCD.createChar(1, arbre);
 LCD.createChar(2, pierre);
 LCD.createChar(3, oiseau);

 LCD.setCursor(7, 0);
 LCD.print("GO!");
 delay(400);
 tone(10, 600);
 delay(100);
 noTone(10);
 LCD.clear();
}

void loop() {
  byte d = 1;
  byte x = 15;
  byte y = 1;

  byte i = random (1, 4);
  if (i == 3) y = 0;
  else y = 1;

  while (x > 0) {
    LCD.clear();
    LCD.setCursor(0, 0);
    LCD.print(level);

    if (digitalRead(A1) == LOW) d = 1;
    if (digitalRead(A1) == HIGH) d = 0;
    if (p > 3) d = 1;

    LCD.setCursor(4, d);
    LCD.print(char(0));
    LCD.setCursor(x, y);
    tone(10, 50);
    LCD.print(char(i));
    noTone(10);

    if (x == 4 && y == d) {
      delay(400);
      tone(10, 50);
      delay(100);
      noTone(10);
      delay(100);
      tone(10, 20);
      delay(300);
      noTone(10);
      LCD.clear();
      delay(200);
      LCD.setCursor(3, 0);
      LCD.print("GAME OVER!");
      delay(600);
      LCD.clear();
      delay(400);
      LCD.setCursor(3, 0);
      LCD.print("GAME OVER!");
      delay(600);
      LCD.clear();
      LCD.setCursor(3, 1);
      LCD.print("LEVEL: ");
      LCD.print(level);
      delay(400);
      LCD.setCursor(3, 0);
      LCD.print("GAME OVER!");
      delay(3000);
      LCD.clear();

      LCD.setCursor(7, 0);
      LCD.print("GO!");
      delay(400);
      tone(10, 600);
      delay(100);
      noTone(10);
      LCD.clear();

      level = 0;
      pause = 400;
      p = 0;
      y = 1;
      x = 0;
      break;
    }

    if (d == 0) { tone(10, 200); delay(100); noTone(10); }
    else { delay(100); }

    delay(pause);
    x = x - 1;
    p = p + 1;
    if (p > 4) p = 0; 
 }

  tone(10, 800);
  delay(20);
  level = level + 1;
  pause = pause - 20;
  if (pause < 0) pause = 0;
}