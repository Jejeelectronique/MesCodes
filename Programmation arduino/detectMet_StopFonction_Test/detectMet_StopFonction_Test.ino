#include "DetecMet.h"  
#include <LiquidCrystal.h>                                                  //Appel de la librairie pour l'ecran LCD.
#include <LcdBarGraph.h>                                                    //Appel de la librairie pour afficher une bargraph sur l'ecran.
#include "Arduino.h"

/*----------------------DECLARATION DES PINS UTILISEES POUR L'ECRAN LCD ET LE BARGRAPH-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
LiquidCrystal lcd(6, 7, 10, 11, 12, 13);                                    //Attribution des pins pour l'écran LCD.
//LcdBarGraph lbg(&lcd, 16, 0, 1);                                            //Attribution des pins pour le bargraph de l'écran LCD
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


typedef enum affi{
  a,
  b
};

affi Typeaffichage = a;

/*----------------------DECLARATION DES PINS UTILISEES POUR LE CONTROLE DE L'ALIMENTATION-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
alimentation arduinoNano(8 , 3 , 3 , &lcd);                                             //Les valeurs en argument de l'appel de classe sont, dans l'ordre : la pin de maintien de l'alimentation et la pin de lecture du bouton stop.
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#define bouttonCalibrage 2

void setup() 
{
pinMode(bouttonCalibrage, INPUT_PULLUP);
lcd.begin(16,2);
Serial.begin(19200);
arduinoNano.alimentation_init();    

wdt_enable(WDTO_2S);
MCUSR = 0;

}

void loop() {
  wdt_reset();


if(!digitalRead(bouttonCalibrage))
{
  Typeaffichage ^= 1;
  while(!digitalRead(bouttonCalibrage));
}


switch (Typeaffichage) {
case a :
  lcd.setCursor(0, 0);
  lcd.print("Cas A");
break;

case b : 
  lcd.setCursor(0, 0);
  lcd.print("Cas B");
break;
}




arduinoNano.stop_alimentation();
}
