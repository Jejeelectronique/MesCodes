#include "steppmotor.h"


#define boutton 10



MoteurPaP moteurHorizontal(2,3,4,5);
MoteurPaP moteurVertical(6,7,8,9);

void setup() {
  pinMode(boutton, INPUT_PULLUP); // Assurez-vous que le bouton est configuré correctement
  moteurHorizontal.init();
  moteurVertical.init();
}

void loop() {
  if (digitalRead(boutton) == LOW) {
    moteurHorizontal.step_plus(360,100);
    //moteurVertical.step_moins(360, 10);

  }
}