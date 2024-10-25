#ifndef RadioAlim_h
#define RadioAlim_h


#include "Arduino.h"
#include <LiquidCrystal.h>

#define LectureNumerique 0
#define LectureAnalogique 1

extern LiquidCrystal lcd;             //Méthode à portée globale, à éviter pour des raisons de conflit et sécurité

class alimentation
{
  public:
    alimentation(int Pin_RST_CPU , int Pin_STOP, int TpsAppui);
    void init();
    void controlOn();


  private:
  const int  _Seuil_off = 650;
  int _Pin_STOP;
  int _Lect_BTN;
  int _RST_CPU;
  int _tempsAppui = 0;
  int _Ctrl_TPS_Appui;
  int _refV;
  bool _ModeAlim = 0;
  bool _init = 1;
  void affichageArret();
  void StopSignal();
  void ResetTpsAppui();
  void StopAlim();
};





#endif