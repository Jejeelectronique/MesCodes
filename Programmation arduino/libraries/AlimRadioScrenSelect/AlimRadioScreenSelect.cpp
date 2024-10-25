#include "AlimRadioScreenSelect.h"



/*----------------------Classe Alimentation------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*-------------------------Fonctions PUBLIC-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
alimentation::alimentation(int Pin_RST_CPU, int Pin_STOP, int TpsAppui, int Btn_nav_Gauche, int Btn_nav_Droite)       //Instanciation de classe
{
  _RST_CPU = Pin_RST_CPU;
  _Pin_STOP = Pin_STOP;
  _tempsAppui = TpsAppui;
  _Ctrl_TPS_Appui = TpsAppui;
  _Btn_nav_Gauche = Btn_nav_Gauche;
  _Btn_nav_Droite = Btn_nav_Droite;
  lcd.createChar(0,_cursor);

}



void alimentation::init()                                     //Initialisation des pin en entrée sortie
{
pinMode(_RST_CPU,OUTPUT);
digitalWrite(_RST_CPU,LOW);
pinMode(_Pin_STOP,INPUT);
pinMode(_Btn_nav_Gauche,INPUT);
pinMode(_Btn_nav_Droite,INPUT);
}



void alimentation::controlOn()
{
  ResetTpsAppui();                                            //Fonction de réinitialisation du compteur du temps d'appui sur le bouton On/Off
  _Lect_BTN = digitalRead(_Pin_STOP);                         //Variable ou l'on stock la valeur relevé sur la pin de lecture du boutton off
  if(_Lect_BTN)
  {
    StopAlim();                                               //Appel de la fonction 
  }
}

void alimentation::ForceShutdown()                            //Fonction permettant de forcer l'arret du systéme
{
  digitalWrite(_RST_CPU,HIGH);
}
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/




/*^^^^^^^^^^^^^^^^^^Fonctions PRIVATE^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
void alimentation::affichageArret()                           //Fonction d'affichage de la fenétre d'arret
{
    lcd.setCursor(0,0);
    lcd.print("Arret du systeme");
    lcd.setCursor(YES,1);
    lcd.print("YES");
    lcd.setCursor(NO,1);
    lcd.print("NO");  
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void alimentation::AffichageSaveData()
{
    lcd.setCursor(0,0);
    lcd.print("Sauvegarder Data");
    lcd.setCursor(YES,1);
    lcd.print("YES");
    lcd.setCursor(NO,1);
    lcd.print("NO"); 
}




void alimentation::PosCurseur()
{
  _Etat_Btn_Droite = digitalRead(_Btn_nav_Droite);            //Lecture des boutons utilisés pour la navigation dans le menu d'arret
  _Etat_Btn_Gauche = digitalRead(_Btn_nav_Gauche);
  if(_Etat_Btn_Droite == HIGH)                
  {
    _PositionCurseur = NO;
  }
  if(_Etat_Btn_Gauche == HIGH)                                //La valeur NO ou YES est stocké dans la variable _PositionCurseur selon le bouton qui à étais enclanché
  {
    _PositionCurseur = YES;
  }
switch (_PositionCurseur)                                     //La variable _PositionCurseur est ensuite utilisé pour définir la postition visuel du curseur, elle seras également utilisé à l'éxtérieur de la fonction pour définir le choix de l'utilisateur
  {
    case NO :
      lcd.setCursor(YES-1,1);
      lcd.print(" ");
      lcd.setCursor(NO-1,1);
      lcd.print(char(0));
      lcd.setCursor(NO,1);
      break;
      
    case YES :
      lcd.setCursor(NO-1,1);
      lcd.print(" ");
      lcd.setCursor(YES-1,1);
      lcd.print(char(0));
      lcd.setCursor(YES,1);
      break;
  }
}


void alimentation::StopAlim()
{
  _tempsAppui--;                                                //Décrémentation de la variable _tempsAppui lorsque le bouton On/Off est enfoncé
  if((_Ctrl_TPS_Appui - _tempsAppui) == _Ctrl_TPS_Appui)        //Si la variable _tempsAppui est tombée à zero alors on éxecute la procédure d'affichage de la fenetre d'arret
  {
    while(_Lect_BTN)                                            //Le code boucle le temps que le bouton On/Off n'a pas étais relacher pour éviter une sélection accidentelle
    {
      _Lect_BTN = digitalRead(_Pin_STOP);
    }
    lcd.clear();
    _selectStop = 1;                                            //Variable utilisé dans la boucle while pour forcé le programme à boucler sur la fenetre d'arret le temps qu'aucun choix n'a étais fait
    while(_selectStop)                                          //Boucle de l'écran d'arret systéme
    {
      affichageArret();                                         //Appel de la fonction d'affichage de la fenetre d'arret
      PosCurseur();                                             //Appel de la fonction qui gére la position du curseur et la sélection du choix
      _Lect_BTN = digitalRead(_Pin_STOP);                       
      if(_Lect_BTN == 1 && _PositionCurseur == YES)             //Code éxecuter si le choix est YES
      {
        while(_Lect_BTN){_Lect_BTN = digitalRead(_Pin_STOP);}
        _PositionCurseur = 0;
        lcd.clear();
        while(_selectStop)
        {
          AffichageSaveData();
          PosCurseur();
          _Lect_BTN = digitalRead(_Pin_STOP);
          if(_Lect_BTN == 1 && _PositionCurseur == YES)
          {
            SaveData(varTest, QuantitePaquets, AdressSaveData);
            _selectStop = 0;
          }
          else if(_Lect_BTN == 1 && _PositionCurseur == NO)
          {
            digitalWrite(_RST_CPU,HIGH);
          }
        }
        digitalWrite(_RST_CPU,HIGH);                            //coupure de l'alimentation
      }
      else if (_Lect_BTN == 1 && _PositionCurseur == NO)        //Code éxecuter si le choix est NO
      {
        _tempsAppui = _Ctrl_TPS_Appui;                          //Mise à zero du compteur
        _selectStop = 0;                                        //Mise à zero de la variable _selectStop qui nous permet ainsi de sortir de la boucle de l'écran d'arret
        lcd.clear();                                        
      }
    }          
  }
  delay(1000);                                                    
}

void alimentation::ResetTpsAppui()                            //Fonction de réinitialisation de la variable de controle du temps d'appui utilisé pour l'arret de la carte                  
{
  if (_Lect_BTN == LOW && _tempsAppui != _Ctrl_TPS_Appui)     //Si le bouton n'est On/Off n'est pas enfoncé et que le compteur du temps d'appui n'est pas à sa valeur d'origine alors on réinitialise le compteur
  {
    _tempsAppui = _Ctrl_TPS_Appui;
    lcd.clear();
  }
}
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
void printce(String affichage,byte col) {
  int ligne=16;
  int resultats;
  
  if (affichage.toInt() != 0 || affichage == "0") { // Vérifie si la variable est un entier
    resultats = (affichage.length() - ligne) / 2;
  } else { // Si ce n'est pas un entier, c'est une chaîne de caractères
    resultats = (ligne - affichage.length()) / 2;
  }

  lcd.setCursor(resultats,col);
  lcd.print(affichage);
}
*/