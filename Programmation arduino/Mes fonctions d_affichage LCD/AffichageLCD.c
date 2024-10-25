int centrage_16(String affichage) {
  int ligne=16;
  int resultats;
  
  if (affichage.toInt() != 0 || affichage == "0") { // Vérifie si la variable est un entier
    resultats = (affichage.length() - ligne) / 2;
  } else { // Si ce n'est pas un entier, alors nous la traitons comme une chaîne de caractères
    resultats = (ligne - affichage.length()) / 2;
  }

  return resultats;
}



void print_centrage_16(String affichage,byte col) {
  int ligne=16;
  int resultats;
  
  if (affichage.toInt() != 0 || affichage == "0") { // Vérifie si la variable est un entier
    resultats = (affichage.length() - ligne) / 2;
  } else { // Si ce n'est pas un entier, alors nous la traitons comme une chaîne de caractères
    resultats = (ligne - affichage.length()) / 2;
  }

  lcd.setCursor(resultats,col);
  lcd.print(affichage);
}

void clear(){
lcd.setCursor(0,0);
lcd.print("                ");
lcd.setCursor(0,1);
lcd.print("                ");
}

void clear0(){
lcd.setCursor(0,0);
lcd.print("                ");
}

void clear1(){
lcd.setCursor(0,1);
lcd.print("                ");
}

void eteindre(){
  int capteur=digitalRead(8);
  int compteur=5;
  if(capteur==1){
    for(int i=0;i<5;i++){

    
    print_centrage_16("Arret dans :",0);
    clear1();
    lcd.setCursor(8,1);
    lcd.print(compteur);
    compteur--;
    delay(1000);
  
  if(compteur==0){
    digitalWrite(8, LOW);
    delay(1000);
  }

  else{
    compteur=5;
  }
  }
}

}

*/
