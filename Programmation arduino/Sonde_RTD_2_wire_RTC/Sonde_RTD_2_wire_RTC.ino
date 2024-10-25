#include <LiquidCrystal.h>
#include <stdio.h>
#include <Wire.h>
#include <RTClib.h>

#define Capteur A0
#define boutton 10

LiquidCrystal lcd(12, 11, 4, 5, 6, 7);


//tempC = (valbrut -114) / 1.96; 
int celsfar = 0;
const int Vpin = 5;
const int bitcan = 1024;
float CapV = 0.0048828125;
long int valbrut;
const int Vref = 0;
void print_centrage_16();
int capboutton;
int tempC;
int tempF;
void lcdclear();
const char *daysOfTheWeek[] = {"Dimanche" , "Lundi" , "Mardi" , "Mercredi" , "Jeudi" , "Vendredi" , "Samedi"};
RTC_DS1307 rtc;

void setup() {

lcd.begin(16,2);
Serial.begin(9600);
Serial.println("V max d'entree = " + String(Vpin));
Serial.println("Bit du Can = " + String(bitcan));
Serial.println("resolution du can en volt = " + String(CapV));
pinMode(Capteur,INPUT);
pinMode(boutton,INPUT);

 #ifndef ESP8266
    while (!Serial); // wait for serial port to connect. Needed for native USB
  #endif

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}


}

void loop() {

DateTime now = rtc.now();
switch (celsfar) {

case(0):

capboutton = digitalRead(boutton);
valbrut = analogRead(A0);
tempC = (valbrut -611) / 2.03; 
lcd.setCursor(1,0);
lcd.print(now.hour()+String("h : ") +String(now.minute()) +String("m : ") +String(now.second()) +String("s"));
lcd.setCursor(0,1);
lcd.print(tempC + String(" ' Celsius"));
Serial.println(valbrut);
delay(100);


if (capboutton == 0){
delay(1000);
lcdclear();
celsfar = 1;
}
break;



case(1):

capboutton = digitalRead(boutton);
valbrut = analogRead(A0);
tempC = (valbrut -611) / 2.03; 
tempF = (tempC * 1.8) + 32;
lcd.setCursor(0,0);
lcd.print(now.hour()+String("h : ") +String(now.minute()) +String("m : ") +String(now.second()) +String("s"));
lcd.setCursor(0,1);
lcd.print(tempF + String(" ' fahrenheit"));
Serial.println(valbrut);
delay(100);

if (capboutton == 0){
delay(1000);
lcdclear();
celsfar = 0;
} 
break;


} 
}



void print_centrage_16(String affichage,byte col) {
  int ligne=16;
  int resultats;
  
  if (affichage.toInt() != 0 || affichage == "0") { // Vérifie si la variable est un entier
    resultats = (affichage.length() - ligne) / 2;
  } else { // Si ce n'est pas un entier, c'est une chaîne de caractères
    resultats = (ligne - affichage.length()) / 2;
  }

  lcd.setCursor(resultats,col);
  lcd.print(affichage);
}

void lcdclear(){

lcd.setCursor(0,0);
lcd.print("                 ");
lcd.setCursor(0,1);
lcd.print("                 ");

}
