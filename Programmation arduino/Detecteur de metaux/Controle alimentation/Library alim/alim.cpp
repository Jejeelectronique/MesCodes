#include "alim.h"


alimentation::alimentation(int pinAlimentation,int pinAlimentationStop)
{
  _pinAlimentation = pinAlimentation;
  _pinAlimentationStop = pinAlimentationStop;
}

void alimentation::alimentation_init()
{

pinMode(_pinAlimentation,OUTPUT);
digitalWrite(_pinAlimentation,HIGH);
pinMode(_pinAlimentationStop,INPUT);
}


void alimentation::stop_alimentation(int duree)
{
    
    if(_pinAlimentationStop >= 0 && _pinAlimentationStop <=13){
      _lecture_Boutton_off = digitalRead(_pinAlimentationStop);   //Variable ou l'on stock la valeur relevé sur la pin de lecture du boutton off
      if(_lecture_Boutton_off == HIGH)
      {
        _tempsAppui++;
        delay(1000);

        if(_tempsAppui > duree)
        {
          digitalWrite(_pinAlimentation,LOW);
        }
      }

      if(_tempsAppui > 0 && _lecture_Boutton_off == LOW)
      {
        _tempsAppui=0;
      }
      }

      else {

        _lecture_Boutton_off = analogRead(_pinAlimentationStop);   //Variable ou l'on stock la valeur relevé sur la pin de lecture du boutton off
          if(_lecture_Boutton_off >= _Seuil_Boutton_off)       //test de condition pour voire si le boutton est enfoncé
          {
            _tempsAppui++;                                     //Variable que l'on incrémente pour faire couper l'alimentation
            delay(1000);
    
          if(_tempsAppui > duree)
          {   //Si la variable atteint la valeur définie alors on coupe le maintient de l'alimentation
            digitalWrite(_pinAlimentation,LOW);              //coupure de l'alimentation        
          }
        }

        if(_tempsAppui > 0 && _lecture_Boutton_off < _Seuil_Boutton_off)  //Test de condition pour voire si le compteur du temps d'appuie est supérieur à 0 et que le boutton a etais relaché, alors il faut réinitialisé le compteur.
        {
          _tempsAppui=0;                                               //réinitialisation du compteur.
        }
        }

    }
