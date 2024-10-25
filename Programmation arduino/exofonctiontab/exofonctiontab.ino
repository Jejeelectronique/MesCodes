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

