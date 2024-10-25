//||||||||||||||||||||||||||||||||||||||||||||||||DASH_BOARD_PROJET||||||||||||||||||||||||||||||||||||||||||||||||||||//
 
 
 #include <genieArduino.h>                                  //  bibliotheque genie 4dsystems
 #include <math.h>
 #include <Arduino.h>
 #include <Wire.h>
 #include "Dash_board.h"                                    //  bibliotheque monitor debug

 #define pressurePin_1 A0                                   //  capteur de pression de suralimentation
 #define pressurePin_2 A1                                   //  capteur de pression d'huile
 #define tempPin A2                                         //  sonde de temperature
 #define tachyPin A3                                        //  tachymetre       
 #define cmdRel_1 1                                         //  commande relai1 pour electrovanne1
 #define cmdRel_2 2                                         //  commande relai2 pour electrovanne2
 #define oxygenPin A4
 #define DELAY1 3000
 #define DELAY2 200



/*--------------------------Déclarations et appels des classes------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
 Genie Genie;                                  
 temperature Temp(tempPin);
 suralimentation suralim (pressurePin_1);
 huile CapteurHuile (pressurePin_2);
 tachy tachymetre(tachyPin);
 relais Relais(cmdRel_1,cmdRel_2);
 airFuel airFuel(oxygenPin);
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



  unsigned long int millis();
  unsigned long int timer = 0;
  unsigned long int timer_tmp;


void setup() 
{
  Serial.begin(115200);
  Genie.Begin(Serial);                                        // Initialise la communication série avec l'écran
  while(!Serial);

  Temp.temp_init();
  suralim.pressionSural_init();
  CapteurHuile.pressionHuile_init();
  tachymetre.tachy_init();
  Relais.relais_init();
  airFuel.airFuel_init();
    
}


void loop() 
{
  timer_tmp = millis();


   Genie.WriteObject(GENIE_OBJ_LED_DIGITS, 1, Temp.traitement_temp());

    if(timer_tmp>= (timer + DELAY1))
    {
     timer= timer + DELAY1;
    }

  Relais.TestPressionSural(suralim.traitement_pressionSural());

   Genie.WriteObject(GENIE_OBJ_LED_DIGITS, 2, suralim.traitement_pressionSural());  // Mettre à jour la jauge de pression de turbo

    if(timer_tmp>= (timer + DELAY2))
    {
     timer= timer + DELAY2;
    }

  Relais.TestPressionHuile(CapteurHuile.traitement_huile());

   Genie.WriteObject(GENIE_OBJ_LED, 0, CapteurHuile.traitement_huile());              // Mettre à jour la LED de pression d'huile

    if(timer_tmp>= (timer + DELAY2))
    {
     timer= timer + DELAY2;
    }
  
   Genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0, tachymetre.traitement_TrsMin());             // Mettre à jour la jauge de tachymètre

    if(timer_tmp>= (timer + DELAY2))
    {
      timer= timer + DELAY2;
    }

   Genie.WriteObject(GENIE_OBJ_LED, 3, airFuel.traitement_airFuel()); 

    if(timer_tmp>= (timer + DELAY2))
    {
      timer= timer + DELAY2;
    }

  //debug(suralim.traitement_pressionSural(), CapteurHuile.traitement_huile(), tachymetre.traitement_TrsMin(), Temp.traitement_temp(), airFuel.traitement_airFuel());
}

 