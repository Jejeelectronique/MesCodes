#ifndef DetecMet_h
#define DetecMet_h


#include "Arduino.h"


void alim();
void alimInit(static int pinAlimentation, static int pinAlimentationStop);

unsigned int Seuil = 650;
static int Tempo;


void ConfigRegistre(int TIMER1_TOP,int RefV);


void affiEchantillon(double echec, double ValeurAffiner0, double ValeurAffiner1, double ValeurAffiner2, double ValeurAffiner3, double amp1, double amp2, double phase1, double phase2, double AmpMoyenne, double phaseMoyenne);


#endif