#include "ArduinoSTL.h"
#include <Wire.h>
#include "rgb_lcd.h"
#include <DHT.h>
DHT dht(A0, 11);
rgb_lcd lcd;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

void setup() 
{
  Serial.begin(9600);
  while(!Serial);
  dht.begin();
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    
    // Print a message to the LCD.
    

    delay(1000);
}

void loop() 
{
  int sensorValue = analogRead(A1); 
  int abcdef = map(sensorValue, 170, 821, 0, 100);
  int temperature = dht.readTemperature();
  int humidite = dht.readHumidity();
   
   
  lcd.setCursor(0, 0);
  lcd.print("th:");
  lcd.print(temperature);
  lcd.print("C");

  lcd.setCursor(8, 0);
  lcd.print("humi:");
  lcd.print(humidite);
  lcd.print("%");
  
  lcd.setCursor(0,1);
  lcd.print("luminosite:");
  lcd.print(abcdef);
  lcd.print("%");
  Serial.println(sensorValue);
  

  delay(2000);
  
}