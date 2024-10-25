#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>
LiquidCrystal lcd(6,7,10,11,12,13);
#define boutton A0
#define gauche A1
#define droite A2 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void print_cent_16();


int level=0;
int position;
int i = 0;
int a = 0;
int speed = 500;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


byte skull[8] = {B11111,B10101,B10101,B01111,B01110,B11111,B10101,B10101};
byte pique[8] = {B11111,B10101,B11111,B00100,B01110,B11011,B10001,B10001};
byte heros[8] = {B11111,B10101,B11111,B00100,B01110,B11011,B10001,B10001};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void setup() {
Serial.begin(9600);
pinMode(boutton, INPUT_PULLUP);
pinMode(gauche, INPUT_PULLUP);
pinMode(droite, INPUT_PULLUP);

lcd.begin(16,2);
lcd.createChar(0, skull);
lcd.createChar(1, pique);
lcd.createChar(2, heros);
int bpause=1;


while(bpause==1){
print_cent_16("pret a",0);
print_cent_16("commencer",1);
delay(200);

if (digitalRead(boutton)==LOW){
lcd.clear();
print_cent_16("c'est parti",0);
print_cent_16("level",1);

delay(1000);
lcd.clear();
bpause=0;
}
}




}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void loop() {


int pos_verti_perso=1;
int pos_mob=15;
int pos_verti_mob=1;
int deplacement=4;
int parti=0;


i = random(0,1);
if (i==0){
  pos_verti_mob=1;
}
else{
  pos_verti_mob=0;
}

if(pos_mob<=1){
lcd.clear();
level = level +1;
print_cent_16(level,0);
speed=speed-20;
delay(1000);



while(parti==0){
if (digitalRead(boutton)==HIGH){
pos_verti_perso=1;
}
if (digitalRead(boutton)==LOW){
pos_verti_perso=0;
}
if (digitalRead(gauche)==LOW){
deplacement=deplacement-1;
}
if (digitalRead(droite)==LOW){
deplacement=deplacement+1;
}

if(deplacement<=1){
  deplacement=1;
}
if(deplacement>=15){
  deplacement=15;




}




lcd.clear();

lcd.setCursor(deplacement,pos_verti_perso);
lcd.print(char(1));

lcd.setCursor(pos_mob,pos_verti_mob);
lcd.print(char(i));


 
 

}

delay(speed);
pos_mob=pos_mob-1;




}
}












//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




int cent_16(String affichage) {
  int ligne=16;
  int resultats;
  resultats = (ligne - affichage.length()) / 2;
  return resultats;
}






int centrage_16(String affichage) {
  int ligne=16;
  int resultats;
  
  if (affichage.toInt() != 0 || affichage == "0") { // Vérifie si la variable est un entier
    resultats = (affichage.length() - ligne) / 2;
  } else { // Si ce n'est pas un entier, c'est une chaîne de caractères
    resultats = (ligne - affichage.length()) / 2;
  }

  return resultats;
}






void print_cent_16(int affichage,byte col) {
  int ligne=16;
  int resultats;
  resultats = (ligne - affichage) / 2;
  lcd.setCursor(resultats,col);
  lcd.print(affichage);
  }

 




