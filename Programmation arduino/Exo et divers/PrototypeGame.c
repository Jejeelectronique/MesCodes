#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Définir les broches pour l'écran LCD

int score = 0; // Initialiser le score
int playerPos = 0; // Initialiser la position du joueur

void setup() {
  lcd.begin(16, 2); // Initialiser l'écran LCD
  lcd.print("Score: 0"); // Afficher le score initial
  lcd.setCursor(0, 1); // Déplacer le curseur à la deuxième ligne
  lcd.print("Position: 0"); // Afficher la position initiale du joueur
}

void loop() {
  if (digitalRead(A0) == HIGH) { // Si le bouton est pressé
    playerPos++; // Déplacer le joueur vers la droite
    lcd.setCursor(10, 1); // Déplacer le curseur à la position du joueur
    lcd.print(playerPos); // Afficher la nouvelle position du joueur
    delay(100); // Attendre un peu pour éviter les mouvements trop rapides
  }

  if (random(100) < 5) { // 5% de chance d'apparition d'un obstacle
    if (playerPos == 15) { // Si le joueur est à la position la plus à droite
      score++; // Augmenter le score
      lcd.setCursor(7, 0); // Déplacer le curseur à la position du score
      lcd.print(score); // Afficher le nouveau score
      playerPos = 0; // Réinitialiser la position du joueur
      lcd.setCursor(10, 1); // Déplacer le curseur à la position du joueur
      lcd.print(playerPos); // Afficher la nouvelle position du joueur
      delay(1000); // Attendre un peu avant de continuer
    } else { // Sinon, le joueur a perdu
      lcd.clear(); // Effacer l'écran LCD
      lcd.print("Game Over!"); // Afficher le message de fin de partie
      lcd.setCursor(0, 1); // Déplacer le curseur à la deuxième ligne
      lcd.print("Score: "); // Afficher le score final
      lcd.print(score); // Afficher le score final
      while (true) { // Attendre indéfiniment
        // Ne rien faire
      }
    }
  }
}
