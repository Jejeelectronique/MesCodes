#include "RadioAlim.h"



/*----------------------Classe Alimentation------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

alimentation::alimentation(int Pin_RST_CPU, int Pin_STOP, int TpsAppui)
{
  _RST_CPU = Pin_RST_CPU;
  _Pin_STOP = Pin_STOP;
  _tempsAppui = TpsAppui + 1;
  _Ctrl_TPS_Appui = TpsAppui;
}

void alimentation::init()
{

pinMode(_RST_CPU,OUTPUT);
digitalWrite(_RST_CPU,LOW);
pinMode(_Pin_STOP,INPUT);
if(_Pin_STOP >= 0 && _Pin_STOP <=13)
{
  _ModeAlim = LectureNumerique;
}
else 
{
  _ModeAlim = LectureAnalogique;
}

}

void alimentation::controlOn()
{

    ResetTpsAppui();
    switch (_ModeAlim)
    {
    case LectureNumerique:

      _Lect_BTN = digitalRead(_Pin_STOP);   //Variable ou l'on stock la valeur relevé sur la pin de lecture du boutton off
      if(_Lect_BTN == HIGH)
      {
        _tempsAppui--;
        StopAlim();
      }
      break;

    case LectureAnalogique:
      _Lect_BTN = analogRead(_Pin_STOP);   
      if(_Lect_BTN >= _Seuil_off)       
      {
        _tempsAppui--;
        StopAlim();                                  
      }
    break;
  }
}



/*-------------------------Fonctions PRIVATE-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void alimentation::affichageArret()
{
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("arret dans : ");
    lcd.setCursor(7,1);
    lcd.print(_tempsAppui);  
    delay(1000);
}

void alimentation::StopSignal()
{
  if((_Ctrl_TPS_Appui - _tempsAppui) == _Ctrl_TPS_Appui)
  {
    affichageArret();   
    digitalWrite(_RST_CPU,HIGH);              //coupure de l'alimentation        
  }
}

void alimentation::ResetTpsAppui()
{
  switch (_ModeAlim)
  {
  case LectureNumerique:
  if (_Lect_BTN == LOW && _tempsAppui != (_Ctrl_TPS_Appui + 1))
  {
    _tempsAppui = _Ctrl_TPS_Appui + 1;
    lcd.clear();
  }
  break;
  case LectureAnalogique:
  if (_Lect_BTN < _Seuil_off && _tempsAppui != (_Ctrl_TPS_Appui + 1))
  {
    _tempsAppui = _Ctrl_TPS_Appui + 1;
    lcd.clear();
  }
  break;
  }
}


void alimentation::StopAlim()
{
  affichageArret();
  StopSignal(); 
}
    
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
