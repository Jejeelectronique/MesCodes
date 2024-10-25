#ifndef Steppmotor_h
#define Steppmotor_h




#include "Arduino.h"




class MoteurPaP {
public:
  MoteurPaP(int pin1, int pin2, int pin3, int pin4);   //Définie les pins du moteur
  void init();                                              //fonction d'initialisaton du moteur, qui comprend les pinMode et la mise à l'état bas des pin utilisé au commencement
  void step_plus(int degres, int vitesse);                  //fonction de pilotage du moteur
  void step_moins(int degres, int vitesse);




private:
  int _moteur[4];
  int _step;
  void Quatrepas_pilotable(int vitesse);                    //fonction qui permet d'établir le comportement du moteur, elle est utilisé dans les fonctions step_plus et step_moins pour piloté le moteur mais nous n'avons pas nécéssité à l'appelé dans le code
};




#endif





