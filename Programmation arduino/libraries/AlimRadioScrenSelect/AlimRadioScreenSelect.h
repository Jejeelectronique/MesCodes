#ifndef AlimRadioScreenSelect_h
#define AlimRadioScreenSelect_h


#include "Arduino.h"
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <Sauvegarde.h>

#define YES 4                                                                                                   
#define NO 10
#define QuantitePaquets 3
#define AdressSaveData 45


extern LiquidCrystal lcd;                                                                                       //Appels d'une instance éxterieur à la librairie. Méthode à portée globale, à éviter pour des raisons de conflit et sécurité.

class alimentation
{
  public:
    alimentation(int Pin_RST_CPU , int Pin_STOP, int TpsAppui, int Btn_nav_Gauche, int Btn_nav_Droite);         //instanciation de la classe
    void init();                                                                                                //Initialisation des pins et variables appelés dans l'instanciation de la classe.  
    void controlOn();
    void ForceShutdown();


  private:
  int _Pin_STOP;
  int _Lect_BTN;
  int _RST_CPU;                   
  int _tempsAppui = 0;                                                                                           //Variable utilisée pour stocker le temps d'appui nécéssaire pour déclencher le shutdown du systéme.
  int _Ctrl_TPS_Appui;                                                                                           //Variable utilisée pour controler la variable temps d'appui.
  int _Btn_nav_Gauche;            
  int _Btn_nav_Droite;
  int _Etat_Btn_Droite;
  int _Etat_Btn_Gauche;
  int _PositionCurseur = 0;                                                                                       //Variable utilisé pour stocker la valeur de la postion du curseur sur l'écran d'arret
  bool _selectStop = 1;                                                                                           //Opérateur booléen utilisé pour forcer le programme à boucler sur l'affichage d'extinction du systéme le temps qu'aucun choix n'as étais éffectuer.
  void affichageArret();                                                                                          //Fonction contenant les paramétres d'affichage de l'écran d'arret, cette fonction est appelé lors ce que le délais d'appui du bouton à atteint le seuil définie pour l'apparition de la fenetre d'arret du systéme.          
  void ResetTpsAppui();                                                                                           //Fonction appelé pour réinitialiser la variable _tempsAppui qui est décrémenter toutes les secondes lors de l'appui sur le bouton on/off
  void StopAlim();                                                                                                //Fonction contenant les paramétres pour mettre à l'arret le systéme .
  void PosCurseur();                                                                                              //Fonction utilisé pour définir la position du curseur au cours de l'écran d'arret du systéme.
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
  void alimentation::SaveDate();
  void alimentation::AffichageSaveData();
};
extern int varTest;

//void printce(String affichage,byte col);
#endif