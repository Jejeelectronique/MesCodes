#include "steppmotor.h"




MoteurPaP::MoteurPaP(int pin1, int pin2, int pin3, int pin4) {      //définition des pin pour le pilotage du moteur
  _moteur[0] = pin1;
  _moteur[1] = pin2;
  _moteur[2] = pin3;
  _moteur[3] = pin4;
  _step = 0;
}




void MoteurPaP::init() {       //initialisation des pin en sortie et à létat bas du moteur définie dans a fonction MoteurPaP
  for (int i = 0; i < 4; i++) {
    pinMode(_moteur[i], OUTPUT);
    digitalWrite(_moteur[i], LOW);
  }
}




void MoteurPaP::Quatrepas_pilotable(int vitesse) {       // fonction qui définie le fonctionnement du moteur (en mode 4 step) les switch case permette de passer d'un pas à l'autre dans les 2sens
  switch (_step) {
    case 0:
      //AB
      digitalWrite(_moteur[0], HIGH);  //A 1
      digitalWrite(_moteur[1], HIGH);  //B 1
      digitalWrite(_moteur[2], LOW);   //C 0
      digitalWrite(_moteur[3], LOW);   //D 0
      delay(vitesse);
      break;
    case 1:
      //BC
      digitalWrite(_moteur[0], LOW);   //A 0
      digitalWrite(_moteur[1], HIGH);  //B 1
      digitalWrite(_moteur[2], HIGH);  //C 1
      digitalWrite(_moteur[3], LOW);   //D 0
      delay(vitesse);
      break;
    case 2:
      //CD
      digitalWrite(_moteur[0], LOW);   //A 0
      digitalWrite(_moteur[1], LOW);   //B 0
      digitalWrite(_moteur[2], HIGH);  //C 1
      digitalWrite(_moteur[3], HIGH);  //D 1
      delay(vitesse);
      break;
    case 3:
      //DA
      digitalWrite(_moteur[0], HIGH);   //A 1
      digitalWrite(_moteur[1], LOW);    //B 0
      digitalWrite(_moteur[2], LOW);    //C 0
      digitalWrite(_moteur[3], HIGH);   //D 1
      delay(vitesse);
      break;








  }
}




void MoteurPaP::step_moins(int degres, int vitesse) {    //fonction à utilisé pour piloté le moteur en définissant le degrés souhaité et la vitesse, Sens antihoraire
  float facteur = 4.25;
  degres *= facteur;
  for (int i = degres; i >= 0; i--) {
    if (_step == 3) {
      _step = 0;
    }
    Quatrepas_pilotable(vitesse);
    _step++;
  }
}




void MoteurPaP::step_plus(int degres, int vitesse) {     //fonction à utilisé pour piloté le moteur en définissant le degrés souhaité et la vitesse, Sens horaire
  float facteur = 4.25;
  degres *= facteur;
  for (int i = degres; i > 0; i--) {
    if (_step == 0) {
      _step = 3;
    }
    Quatrepas_pilotable(vitesse);
    _step--;
  }
}





