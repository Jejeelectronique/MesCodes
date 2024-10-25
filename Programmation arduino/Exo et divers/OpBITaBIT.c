#include <stdio.h>

void ecritOctet();
/*
unsigned int cpt;

void setup()  
{ 
  pinMode (13, OUTPUT);      // On définit comme étant une "sortie", la pin où est branché la LED sur l'Arduino Uno
  
  // Paramétrage du prescaler


  // Paramétrage du "mode de fonctionnement" du timer1 en "Normal"
  //    -> c'est à dire que le compteur timer1 va compter jusqu'à son maximum, puis revenir à 0, en levant un drapeau au passage (bit TOV1)
  //    -> pour activer ce mode, il faut mettre les bits WGM10, WGM11, WGM12, et WGM13 à 0 (nota : les 2 premiers se trouvent dans le registre TCCR1A, et les 2 autres, dans TCCR1B)
  //    -> pour ce faire, on va se servir de la fonction arduino "bitClear", qui permet de mettre à "0" un bit spécifique, dans un registre donné
  bitClear(TCCR1A, WGM10);
  bitClear(TCCR1A, WGM11);            // Nota : WGM10 et WGM11 se trouvent dans le registre TCCR1A
  bitClear(TCCR1B, WGM12);
  bitClear(TCCR1B, WGM13);            // tandis que WGM12 et WGM13 se trouvent dans le registre TCCR1B

  // Puis on paramètre le prédiviseur du timer1, pour qu'il divise la fréquence issue du prescaler par 64
  //    -> pour faire une division par 64, il faut mettre le bit CS12 à 0, CS11 à 1, et CS10 à 1 également (voir la partie sur les prédiviseurs, pour plus d'infos)
  //    -> et comme juste avant, on va se servir de la fonction "bitClear" pour mettre un bit à 0, et compléter cela avec la fonction "bitSet", pour mettre un autre bit à 1
  bitClear(TCCR1B, CS12);
  bitSet(TCCR1B, CS11);
  bitSet(TCCR1B, CS10);

  // Nota : ici, j'ai tout décomposé pour les "débutants". Mais sachez qu'on aurait pu directement renseigner les registres TCCR1A et TCCR1B, pour aller plus vite
  // Pour cela, il aurait suffit d'écrire les 2 lignes suivantes, pour renseigner ces deux registres :
  //              TCCR1A = 0b00000000;    // pour mettre WGM10 et WGM11 à 0 
  //              TCCR1B = 0b00000011;    // pour mettre WGM12 et WGM13 à 0, et activer la division par 64 


  // Enfin, on fait démarrer le timer1 non pas à 0, mais à la valeur 34286 (pour rappel, ce timer 16 bits compte jusqu'à 65535, puis revient à 0, en levant au passage le flag TOV1)
  TCNT1 = 3035;
  Serial.begin(9600);
 

} 
 
void loop()  
{ 
Serial.println(cpt);
  // À chaque tour de boucle, on test si le bit drapeau "TOV1", contenu dans le registre TIFR1, est levé (c'est à dire à "1")
  // Ainsi, on saura que le timer1 a compté un nombre précis de fois (depuis nos "34286" initiaux), correspondant à nos 500 ms (qui alternés, font bien nos 1 Hz voulus)
  if (bitRead(TIFR1, TOV1) == 1)
  { 
    TCNT1 = 3035;
    cpt++;
  }

  
  if (cpt == 2){
    
    // On en profite pour rabaisser le drapeau ayant signalé l'overflow (bit TOV1), sinon il restera toujours à 1, et on se serait plus jamais averti
    bitSet(TIFR1,TOV1);       // Nota : chose très particulière ici, il faut renvoyer la valeur 1 sur le bit TOV1 pour qu'il passe à 0
                              //        (c'est le constructeur qui impose cette méthode d'acquittement)

    // Puis on inverse l'état de la LED (si elle était allumée, alors on l'éteint, et si elle était éteinte, alors on l'allume)
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));

    cpt = 0;
  

  // Et... on boucle à l'infini ! 
}
}

*/

void setup(){

Serial.begin(9600);


byte registreA=56;


byte registreB=54;


Serial.print("Registre A =");
//Serial.println(registreA[0]+String(registreA[1])+String(registreA[2]+String(registreA[3])+String(" ")+String(registreA[4])+String(registreA[5])+String(registreA[6])+String(registreA[7])));
ecritOctet(registreA);
/*Serial.print("Registre B =");
Serial.println(registreB[0]+String(registreB[1])+String(registreB[2]+String(registreB[3])+String(" ")+String(registreB[4])+String(registreB[5])+String(registreB[6])+String(registreB[7])));
*/



Serial.print("resultat de l'operation BIT a BIT = ");
//Serial.println(registreA[0]+String(registreA[1])+String(registreA[2]+String(registreA[3])+String(" ")+String(registreA[4])+String(registreA[5])+String(registreA[6])+String(registreA[7])));



}



void loop(){



}



void ecritOctet(byte var) {
  for (byte test = 0x80; test; test >>= 1) {
    Serial.write(var  & test ? '1' : '0');
  }
  Serial.println();
}