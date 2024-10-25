

void setup() {

  byte octetA, octetB, resultat;

  Serial.begin(9600); // initialisation de la communication série
  /*
  Serial.println("Demonstration d'operations bit a bit");

  randomSeed(analogRead(0));
  octetA = random(255);
  octetB = random(255);

  Serial.println();
  Serial.print("Valeur de l'octet A:  ");
  ecritOctet(octetA);
  Serial.print("Valeur de l'octet B:  ");
  ecritOctet(octetB);
  Serial.println();
  Serial.println("L'operateur NON binaire (~) inverse tous les bits de l'octet:");
  resultat = ~octetA;
  Serial.print("   ~A = ");
  ecritOctet(resultat);;
  resultat = ~octetB;
  Serial.print("   ~B = ");
  ecritOctet(resultat);
  Serial.println();

  Serial.println("L'operateur ET binaire (&) donne 1 si les deux bits valent 1,");
  Serial.println("sinon le resultat est 0");
  Serial.print("   A & B = ");
  resultat = octetA & octetB;
  ecritOctet(resultat);
  Serial.println();

  Serial.println("L'operateur OU binaire (|) donne 0 si les deux bits valent 0,");
  Serial.println("sinon le resultat est 1");
  Serial.print("   A | B = ");
  resultat = octetA | octetB;
  ecritOctet(resultat);
  Serial.println();

  Serial.println("L'operateur OU EXCLUSIF binaire (^) donne 1 si un bit est 1");
  Serial.println("alors que l'autre est 0, sinon le resultat est 0");
  Serial.print("   A ^ B = ");
  resultat = octetA ^ octetB;
  ecritOctet(resultat);
  Serial.println();

  Serial.println("L'operateur DECALAGE VERS LA DROITE (>>) deplace chaque octet");
  Serial.println("vers la droite du nombre de positions specifie (les vides deviennent 0).");

  for (int i = 0; i <= 7; i++) {
    Serial.print("   A >> ");
    Serial.print(i);
    Serial.print(" = ");
    resultat =  octetA >> i;
    ecritOctet(resultat);
  }

  Serial.println("");

  Serial.println("L'operateur DECALAGE VERS LA GAUCHE (<<) deplace chaque octet");
  Serial.println("vers la GAUCHE du nombre de positions specifie (les vides deviennent 0).");

  for (int i = 0; i <= 7; i++) {
    Serial.print("   A << ");
    Serial.print(i);
    Serial.print(" = ");
    resultat =  octetA << i;
    ecritOctet(resultat);
  }

  Serial.println("");

  Serial.println("Determination de la valeur de chaque bit.");
  Serial.println("Le bit numero 0 est le dernier a droite.");

  for (int i = 0; i <= 7; i++) {
    Serial.print("  Le bit numero ");
    Serial.print(i);
    Serial.print(" de A = ");
    bool resultatBool =  octetA & (1 << i); 
    Serial.println(resultatBool);
  }

  Serial.println("");


  Serial.println("Reglage d'un bit a 1, sans modifier les autres bits.");

  for (int i = 0; i <= 7; i++) {
    Serial.print("  Bit numero ");
    Serial.print(i);
    Serial.print(" de A mis a 1: ");
    resultat =  octetA | (1 << i);
    ecritOctet(resultat);
  }

  Serial.println("");

  Serial.println("Reglage d'un bit a 0, sans modifier les autres bits.");

  for (int i = 0; i <= 7; i++) {
    Serial.print("  Bit numero ");
    Serial.print(i);
    Serial.print(" de A mis a 0: ");
    resultat =  octetA & ~(1 << i);
    ecritOctet(resultat);
  }

  Serial.println("");


  Serial.println("Inversion d'un bit, sans modifier les autres bits.");

  for (int i = 0; i <= 7; i++) {
    Serial.print("  Bit numero ");
    Serial.print(i);
    Serial.print(" inverse: ");
    resultat = octetA ^ (1 << i);
    ecritOctet(resultat);
  }

  Serial.println("");

  Serial.println();

  Serial.println("Appuyez sur le bouton reset pour generer une nouvelle paire d'octets");
  Serial.println("------------------------------------------------------");
  Serial.println();
}

// cette fonction écrit la valeur de l'octet, incluant les premiers zéro, s'il y a lieu

void ecritOctet(byte var) {
  for (byte test = 0x80; test; test >>= 1) {
    Serial.write(var  & test ? '1' : '0');
  }
  Serial.println();
  */
  Serial.println(ADMUX,BIN);
  ADMUX = 0xFF;
  Serial.println(ADMUX,BIN);
  ADMUX &=~ (1<<6) &~ (1<<4);
  Serial.println(ADMUX,BIN);
  ADMUX = (5<<0);
  Serial.println(ADMUX,BIN);
}





void loop() {

  // tout est dans setup

}