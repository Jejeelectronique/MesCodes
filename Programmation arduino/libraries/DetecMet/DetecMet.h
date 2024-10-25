#ifndef DetecMet_h
#define DetecMet_h


#include "Arduino.h"
#include <LiquidCrystal.h>
#include <avr/wdt.h>

#define LectureNumerique 0
#define LectureAnalogique 1
#define _Btn_OFF_and_Left digitalRead(_pinAlimentationStop)
#define _Btn_Calib_and_Right digitalRead(2)

#define PosCursor_no 2
#define PosCursor_yes 12

class alimentation
{
  public:
    alimentation(int pinAlimentation , int pinAlimentationStop , int duree , LiquidCrystal *lcd);
    void alimentation_init();
    void stop_alimentation();


  private:
  unsigned char tpsAppD = 0;
  unsigned char tpsAppG = 0;
  int _pinAlimentation;
  int _pinAlimentationStop;
  int _tempsAppui = 0; 
  int _TpsAppuiPrec = 0;
  int _refV;
  bool _State_Stop_BtnG = 0;
  bool _State_RST_BtnD = 0;
  byte _PosCurs = 0;
  LiquidCrystal *_lcd;                    //Il faut impérativement déréférencer le pointeur dés ca déclaration pour pouvoir récuper la valuer de la classe externe
  void alimentation::ResetTimer();
  void alimentation::PrintStopScreen();
  void alimentation::Print_Cursor_Pos_No();
  void alimentation::Print_Cursor_Pos_Yes();
  bool alimentation::screenSelect();
  bool alimentation::Quit_Or_Continue();

  typedef enum StatusAffichage
  {
    non,
    oui
  }StatusAffichage;


    byte _cursor[8] = 
  {
    0b10000,
    0b11000,
    0b11100,
    0b11110,
    0b11111,
    0b11110,
    0b11100,
    0b11000
  };

};


//extern LiquidCrystal lcd();             //Méthode à portée globale, à éviter pour des raisons de conflit et sécurité

void ConfigRegistre(int TIMER1_TOP,int RefV);
void affiEchantillon(double echec, double ValeurAffiner0, double ValeurAffiner1, double ValeurAffiner2, double ValeurAffiner3, double amp1, double amp2, double phase1, double phase2, double AmpMoyenne, double phaseMoyenne);


typedef enum stateDel{
  NoDel,
  DelEnCours,
}stateDel;

typedef enum StateLectureBtn{
  LectureEffectuer,
  Clear
}StateLectureBtn;

typedef enum ModeEcran{
  Mode_Decrementation,
  Mode_Arret
}ModeEcran;


extern StateLectureBtn StateLectBtn;

bool MydelayMS(long unsigned int delay);
extern stateDel DelState;
extern long unsigned int Milliseconde;
extern long unsigned int LastmilliSeconde;

#endif