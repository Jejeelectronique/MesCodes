int alea;
#include <ArduinoSTL.h>
#define TAILLE_TABLEAU 100
int tab[TAILLE_TABLEAU];
int cpt=1;
int valeur;
int pair;
int impair;

void setup() {
  Serial.begin(9600);
  while(!Serial);
  randomSeed(analogRead(0));
}

void loop() 
{
cpt=1;
pair=0;
impair=0;
Serial.println("valeur de mon tableau : ");

for(int i=0 ; i<TAILLE_TABLEAU ; i++)
{

tab[i] = random(100);

Serial.print("la Valeur du tableau numero ");
Serial.print(cpt);
Serial.print("  est de : ");
Serial.println(tab[i]);


cpt++;
delay(100);


if(tab[i]%2==0)//Incrémentation du compteur
{
pair++;
}

else
{
impair++;
}

if(cpt==101)
{
Serial.print("voici la quantité de nombres pair : ");
Serial.println(pair);

Serial.print("voici la quantité de nombres impair : ");
Serial.println(impair);
Serial.println("entrer une commande pour reinitialiser le code");
scanf("%d");


}
}



}