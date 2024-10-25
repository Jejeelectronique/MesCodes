#include "ArduinoSTL.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(12 , 11 , 5 , 4 , 3 ,2);
int sensorValue;


void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.setCursor(1, 0);
  lcd.print("Temperature:");
  Serial.print("Temperature");
}

void loop() {
  sensorValue = analogRead(A0);
  float Temperature = sensorValue * (5.0 / 1023.0);
  lcd.setCursor(0, 1);
  lcd.print(Temperature);
  Serial.print(Temperature);
  lcd.print("  c");
  delay(100);
  
}
