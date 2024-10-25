#include "alim.h"
#include "rgb_lcd.h"
#include <LiquidCrystal.h>


LiquidCrystal lcd(6, 7, 10, 11, 12, 13);

alimentation arduinoNano(8,A1);


void setup() {
  arduinoNano.alimentation_init();
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(2, 0);
  lcd.print("GO !");
  delay(3000);
  lcd.clear(); 
}

void loop() {

  arduinoNano.stop_alimentation(3);

}

