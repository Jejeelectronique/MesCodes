 #include "Sonde2WIRE.h"

LiquidCrystal lcd (12,11,4,5,6,7);

twoWire::twoWire(int capteur,int boutton)

{
  _capteur  = capteur;
  _boutton  = boutton;
}


void twoWire::twoWire_init()
{
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(_capteur,INPUT);
  pinMode(_boutton,INPUT);
  Serial.println("V max d'entree = " + String(_Vpin));
  Serial.println("Bit du Can = " + String(_bitcan));
  Serial.println("resolution du can en volt = " + String(_CapV));
}

void twoWire::codeSource()
{
  switch (_celsfar) {

case(0):

_capboutton = digitalRead(_boutton);
_valbrut = analogRead(_capteur);
_tempC = (_valbrut -611) / 2.03; 
print_centrage_16("Temperature",0);
lcd.setCursor(0,1);
lcd.print(_tempC + String(" ' Celsius"));
Serial.println(_valbrut);
delay(100);


if (_capboutton == 0){
delay(1000);
lcdclear();
_celsfar = 1;
}
break;



case(1):

_capboutton = digitalRead(_boutton);
_valbrut = analogRead(_capteur);
_tempC = (_valbrut -611) / 2.03; 
_tempF = (_tempC * 1.8) + 32;
print_centrage_16("Temperature",0);
lcd.setCursor(0,1);
lcd.print(_tempF + String(" ' fahrenheit"));
Serial.println(_valbrut);
delay(100);

if (_capboutton == 0){
delay(1000);
lcdclear();
_celsfar = 0;
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



