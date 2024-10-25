#include "Modellib.h"


//LiquidCrystal lcd (12,11,4,5,6,7); appel ici d'une autre classe si nécéssaire

exemple::exemple(int capteur,int boutton)

{
  _Variable_exemple4  = capteur;
  _Variable_exemple5  = boutton;
}


void exemple::exemple_init()
{
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(_Variable_exemple4,INPUT);
  pinMode(_Variable_exemple5,INPUT);
  Serial.println("V max d'entree = " + String(_Variable_exemple1));
}

void exemple::codeSource()
{
//code.....
}



void FonctionExemple1(String affichage,byte col) {
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

void FonctionExemple2(){

lcd.setCursor(0,0);
lcd.print("                 ");
lcd.setCursor(0,1);
lcd.print("                 ");

}

