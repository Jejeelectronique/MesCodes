#include "AlimRadioScreenSelect.h"
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <Wire.h>

#define Pin_RST_CPU 4
#define Pin_BTN_ONOFF 5
#define DelaisSTOP 2
#define BtnGauche 2
#define BtnDroite 3
#define NombresDePaquet 3
#define AdresseMemoire 45

#define DelaisMillis 2000

int varTest = 0;
LiquidCrystal lcd (6,7,8,9,10,11);
alimentation MonAlimentationRadio(Pin_RST_CPU, Pin_BTN_ONOFF, DelaisSTOP, BtnGauche, BtnDroite);
unsigned long Timer = 0;
unsigned lastTimer = Timer;

void setup() 
{
  lcd.begin(16,2);
  Serial.begin(9600);
  while(!Serial);
  MonAlimentationRadio.init();
  varTest = LectureData(NombresDePaquet,AdresseMemoire);
}

void loop() {
  Timer = millis();
  lcd.setCursor(0, 1);
  lcd.print("program run...");
  lcd.setCursor(7, 0);
  lcd.print(varTest);
  MonAlimentationRadio.controlOn();
  if ((Timer - lastTimer) >= DelaisMillis)
  {
    varTest += 1500;
    lastTimer = Timer;
  }
  if (digitalRead(BtnDroite))
  {
    ResetData(NombresDePaquet, AdresseMemoire);
  }
}