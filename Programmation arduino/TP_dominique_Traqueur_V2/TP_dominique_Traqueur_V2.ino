#include "StepperControl.h"

StepperControl::StepperControl(int moteur[4]) {
  _moteur = moteur;
  _step = 0;
}

void StepperControl::init() {
  for (int i = 0; i < 4; i++) {
    pinMode(_moteur[i], OUTPUT);
    digitalWrite(_moteur[i], LOW);
  }
}

void StepperControl::Quatrepas_pilotable(int vitesse) {
  switch (_step) {
    case 0:
      //AB
      digitalWrite(_moteur[0], HIGH);  //A 1
      digitalWrite(_moteur[1], HIGH);  //B 1
      digitalWrite(_moteur[2], LOW);   //C 0
      digitalWrite(_moteur[3], LOW);   //D 0
      delay(vitesse);
      break;
    // ...
  }
}