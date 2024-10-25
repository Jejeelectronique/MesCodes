#define Boutton_off A3
#define AlimMosfetCarte 8
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 100;
const int colorG = 0;
const int colorB = 0;

const int Seuil_Boutton_off = 850;
int tempsAppui = 0;
int lecture_Boutton_off;


void setup() {
  
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  Serial.begin(9600);
  pinMode(Boutton_off,INPUT);
  pinMode(AlimMosfetCarte, OUTPUT);                       //la pin D8 peut être connecte a la grille d'un mosfet canal n pour un montage avec maintien alim
  digitalWrite(AlimMosfetCarte,HIGH);
  lcd.setCursor(2, 0);
  lcd.print("c'est parti !");
  delay(3000);
  lcd.clear(); 

}

void loop() {
  

  lecture_Boutton_off = analogRead(Boutton_off);   //Variable ou l'on stock la valeur relevé sur la pin de lecture du boutton off

   if(lecture_Boutton_off >= Seuil_Boutton_off)       //test de condition pour voire si le boutton est enfoncé
    {
    tempsAppui++;                                     //Variable que l'on incrémente pour faire couper l'alimentation
    delay(1000);
    

    if(tempsAppui >= 3){                              //Si la variable atteint la valeur définie alors on coupe le maintient de l'alimentation
    digitalWrite(AlimMosfetCarte,LOW);              //coupure de l'alimentation        
  }
  }

    if(tempsAppui > 0 && lecture_Boutton_off < Seuil_Boutton_off)  //Test de condition pour voire si le compteur du temps d'appuie est supérieur à 0 et que le boutton a etais relaché, alors il faut réinitialisé le compteur.
    {
    tempsAppui=0;                                               //réinitialisation du compteur.
  }

  Serial.println("temps d'appuie" +String(tempsAppui));
  Serial.println("valeur du boutton off" +String(lecture_Boutton_off));
  lcd.setCursor(0, 0);
  lcd.print("tps d'appuye");
  lcd.setCursor(0, 1);
  lcd.print(tempsAppui);
  
}