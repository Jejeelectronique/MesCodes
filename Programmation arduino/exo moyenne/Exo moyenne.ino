#include <ArduinoSTL.h>
float moyenne;
int nb;

void setup() {

   
    Serial.begin(9600);
    while(!Serial);


  Serial.println("Entrer le total de note");
  scanf("%d" ,&nb);
  int tabnote[nb];


for (int i=0; i<nb; i++)
{

Serial.println("entre la note numero" + String(i+1));
scanf("%d" ,&tabnote[i]);
Serial.println("ca valeur est de :" + String(tabnote[i]));
Serial.println("total des notes a rentrer restantes : " + String(nb-i) + "\n");

}


moyenne = fonction_moyenne(tabnote,nb);
Serial.print("voici la moyenne : " + String(moyenne));
Serial.println("");
delay(500);

}


void loop() {}


float fonction_moyenne (int letableau[], int lenombredindex){
float somme=0;
for(int i=0 ; i<lenombredindex; i++){
somme=somme+letableau[i];
}
return(somme/lenombredindex);
}

