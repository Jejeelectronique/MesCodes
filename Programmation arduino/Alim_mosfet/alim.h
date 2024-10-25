#include "LiquidCrystal.h"
/////Code rédigé par J.C le 21/10/2023//////

/*
Cette bibliothèque est destinée à piloter l'alimentation de la carte Arduino à l'aide d'un montage de transistors et d'un bouton-poussoir qui permet d'allumer et d'éteindre la carte numériquement.

Exemple d'utilisation du code en utilisant le nom de classe 'NomArbitraire':

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "alim.h"

alimentation NomArbitraire(8,A1);

void setup()
{
  NomArbitraire.alimentation_init();
}

void loop()
{
  NomArbitraire.stop_alimentation(10);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Comme indiqué, le nom de la classe peut être choisi arbitrairement.


*/

#ifndef alim_h
#define alim_h


#include "Arduino.h"
#include <LiquidCrystal.h>


class alimentation
{
  public:
    alimentation(int pinAlimentation, int pinAlimentationStop);
    void alimentation_init();
    void stop_alimentation(int duree);


  private:
  const int  _Seuil_Boutton_off = 850;
  int _pinAlimentation;
  int _pinAlimentationStop;
  int _lecture_Boutton_off;
  int _tempsAppui = 0;
  LiquidCrystal &lcd;
};


#endif