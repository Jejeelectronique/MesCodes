/***************************************************************************
  This is a library for the BMP280 humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BMP280 Breakout
  ----> http://www.adafruit.com/products/2651

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include <LiquidCrystal.h>
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const float fact_lum = 0.263;
float PourcentageLuminosite;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#define duree 3   //Variable de pilotage du temp de défilement de l'écran LCD
int etat=0;
#define LDR A1  // composante photoresistor sur la pin A1

#define BMP_SCK  (13)
#define BMP_MISO (12) //Ou "SDO" sur le module
#define BMP_MOSI (11) //Ou "SDI" sur le module 
#define BMP_CS   (10)

//Adafruit_BMP280 bmp; // I2C
//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);
unsigned int value;

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  while ( !Serial ) delay(100);   // wait for native usb
  Serial.println(F("BMP280 test"));
  unsigned status;
  //status = bmp.begin(BMP280_ADDRESS_ALT, BMP280_CHIPID);
  status = bmp.begin();
  if (!status) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                      "try a different address!"));
    Serial.print("SensorID was: 0x"); Serial.println(bmp.sensorID(),16);
    Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
    Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
    Serial.print("        ID of 0x60 represents a BME 280.\n");
    Serial.print("        ID of 0x61 represents a BME 680.\n");
    while (1) delay(10);
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

     // initialise la communication avec le PC

   // initialise les broches
   pinMode(LDR, INPUT);
}

void loop() {

  switch (etat){

  case 0 :
  for(int i=0;i<duree;i++){
    lcd.setCursor(0, 0);
    lcd.print("Temperature : ");
    lcd.setCursor(0,1);
    lcd.print(bmp.readTemperature());
    Serial.print(F("Temperature = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    delay(1000);
    }
    etat++;
    lcd.clear();
  break;
  
  case 1 :
  for(int i=0;i<duree;i++){
    lcd.setCursor(0, 0);
    lcd.print("Pression PA: ");
    lcd.setCursor(0,1);
    lcd.print(bmp.readPressure());
    Serial.print(F("Pressure = "));
    Serial.print(bmp.readPressure());
    Serial.println("Pa");
    delay(1000);
    }
    etat++;
    lcd.clear();
  break;


  case 2 :
  for(int i=0;i<duree;i++){

    lcd.setCursor(0, 0);
    lcd.print("altitude : ");
    lcd.setCursor(0,1);
    lcd.print(bmp.readAltitude(1013.25));
    Serial.print(F("Approx altitude = "));
    Serial.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! */
    Serial.println(" m");
    delay(1000);
  }
  etat++;
  lcd.clear();
  break;

  case 3 :
  for(int i=0;i<duree;i++){
       // mesure la tension sur la broche A1
   value = analogRead(LDR);
   Serial.println(value);
    PourcentageLuminosite = value * fact_lum;
    lcd.setCursor(0,0);
    lcd.print("Luminosite:");
    lcd.setCursor(0,1);
    lcd.print(value);
    Serial.print("Luminosite:");
    Serial.print(value); /* Adjusted to local forecast! */
    Serial.println("lumen");
    Serial.print("%Lum ");
    Serial.print(PourcentageLuminosite);
    delay(1000);
  }
  etat++;
  PourcentageLuminosite=0;
  lcd.clear();
  break;
}
if (etat >= 4)
{
  etat=0;
}
}