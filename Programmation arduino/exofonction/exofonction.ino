#include <ArduinoSTL.h>
int tableau1[10]{10,12,14,12,7,5,4,7,8,9};
int tableau2[10]{0,0,0,0,0,0,0,0};
int tailletableau = 10;



void setup() {
  Serial.begin(9600);
  while(!Serial);
  
  Serial.println("tableau 1");
  fonctionaffichage (tableau1 , tailletableau);

  Serial.println("tableau 2");
  fonctionaffichage (tableau2, tailletableau);

  Serial.println("copie du tableau :");
  copie(tableau1, tableau2, tailletableau);

  Serial.println("tableau 1 :");
  fonctionaffichage(tableau1,tailletableau);

  Serial.println("tableau 2 :");
  fonctionaffichage(tableau2,tailletableau);

}

void loop() {
}


void fonctionaffichage (int tableau, int tailletableau){

 for (int i=0; i<tailletableau; i++){
    
    Serial.print(i);
    Serial.print(" ");
  }
Serial.println(" ");

for (int i=0; i<tailletableau; i++){

Serial.print(tailletableau);
Serial.print(" ");

}
Serial.println(" ");
}

void copie (int tableausource[], int tableaucible[], int tailletableau)
{

for(int i=0; i<tailletableau;i++)

{
tableaucible[i] = tableausource[i];
}
}


void swap(int tableau[], int val1, int val2, int case)
{
case=tableau[val1];
tableau[val1]=tableau[val2];
tableau[val2]=case;
}





