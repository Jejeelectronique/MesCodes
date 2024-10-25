#include <ArduinoSTL.h>
int tableau[10]{10,12,14,12,7,5,4,7,8,9};
int tailletableau = 10;
int val1;
int val2;
int caseM;


void setup() {
  Serial.begin(9600);
  while(!Serial);
  

}

void loop() {

fonctionaffichage(tableau , tailletableau);

Serial.println("rentrer la 1er valeur : ");
scanf("%d" , &val1);
Serial.println(" ");

Serial.println("rentrer la 2eme valeur : ");
scanf("%d" , &val2);
Serial.println(" ");

Serial.print ("voici la valeur du 1er tableau : ");
Serial.println (val1);
Serial.print ("voici la valeur du 2 eme tableau : ");
Serial.println (val2);



swap(val1, val2, tableau, caseM);


fonctionaffichage(tableau , tailletableau);

scanf("%d");
}


void fonctionaffichage (int tableau, int tailletableau){

 for (int i=0; i<tailletableau; i++){
    
    Serial.print(i);
    Serial.print(" ");
  }
Serial.println(" ");

for (int i=0; i<tailletableau; i++){

printf("%5d" , &tableau[i]);
Serial.print(" ");


}
Serial.println(" ");
}


void swap(int val1, int val2, int tableau[], int caseM){

caseM=tableau[val1];
tableau[val1]=tableau[val2];
tableau[val2]=caseM;

}




