#ifndef Dash_board_h
#define Dash_board_h

#include "Arduino.h"







/*--------------------Class temperature---------------------------------------------------------------------------------------------------------------------------------------------*/
class temperature
{
	public : 
		temperature(int tempPin);
		void temp_init ();
		float traitement_temp();

	private :
		double _r0 =10000.0;                                        //  resistance ctn à 15°C
		double _rs = 280.0;                                         //  resistance en serie
		float _temperature = 0.0;                                   //  temperature moteur en °C
		int _pinCateurTemp;
		float _tempVal;                                        // Valeur temperature pour calcul
		int _Vctn = 0;                                           // Tension sonde ctn
 		int _vin = 5.0;                                          //  tension d'alimentation
 		int _Rctn = 0.0;                                         // Resistance sonde ctn
 		int _excel = 3950.0;                                     //  issu d'excel
};
/*--------------------Fin de class temperature---------------------------------------------------------------------------------------------------------------------------------------------*/










/*--------------------Class Suralimentation---------------------------------------------------------------------------------------------------------------------------------------------*/
class suralimentation
{
	public : 

		suralimentation(int PinpressionSural);
		void pressionSural_init();
		float traitement_pressionSural();

	private :
		float _lecturePin;
		float _pressionSural = 0.0;                                 //  pression de suralimention (pression admission moteur)
		int _pinCapteurSuralim;
};
/*--------------------Fin de class Suralimentation---------------------------------------------------------------------------------------------------------------------------------------------*/









/*--------------------Class pression d'huile---------------------------------------------------------------------------------------------------------------------------------------------*/
class huile
{
	public : 
		huile(int pinCapteurHuile,int pinledPressHuileMin);
		void pressionHuile_init();
		float traitement_huile();
	private :
		float _lecturePinH;
		float _pressionHuile = 0.0;                                  //  pression d'huile
		int _pinCapteurHuile;
        int _pinledPressHuile;
        int _pressHuileMin = 2;

};
/*--------------------Fin de class pression d'huile---------------------------------------------------------------------------------------------------------------------------------------------*/









/*--------------------Class tachy---------------------------------------------------------------------------------------------------------------------------------------------*/
class tachy
{
	public : 
		tachy(int Pintachy);
		void tachy_init();
		float traitement_TrsMin();

	private :
		int _tachy = 0;
		int _pinCapteurTachy;                                             //  compte tours moteur en Trs/min
		float _lecturePinT;

};
/*--------------------Fin de class tachy---------------------------------------------------------------------------------------------------------------------------------------------*/











/*--------------------Class relais---------------------------------------------------------------------------------------------------------------------------------------------*/
class relais
{
	public : 
		relais(int PinRelais1,int PinRelais2);
		void relais_init();
		void TestPressionSural(float pressRefSural,float Valsuralim);
		void TestPressionHuile(float pressRefHuile,float ValHuile);


	private :
		int _PinRelais1;
		int _PinRelais2;                                             //  compte tours moteur en Trs/min
		float _press_RefSural = 1.5;                                 //  pression limite d'admission en Bar
 		float _press_RefHuil = 3.0;                                  //  pression limite de lubrification en Bar*
 		float _ValSurAlim;
 		float _ValHuile;

 		//Genie &test;
};
/*--------------------Fin de class relais---------------------------------------------------------------------------------------------------------------------------------------------*/







/*--------------------Class airFuel---------------------------------------------------------------------------------------------------------------------------------------------*/
class airFuel
{
	public :
	airFuel(int oxygenPin);
	void airFuel_init();
	float traitement_airFuel();


	private :
	float _lecturePinA;
	int _pinOxygen;
	float _airFuelRatio = 0.0;                                  //  ratio air/essence 
  	float _oxygenVolts = 0.0;                                   //  mesure de la sonde 
};
/*--------------------Fin de class airFuel---------------------------------------------------------------------------------------------------------------------------------------------*/










/*-------------------fonction debug---------------------------------------------------------------------------------------------------------------------------------------------*/
void debug(float pressionSural, float pressionHuil, float tachy, float temperature,float airFuelRatio);
/*--------------------Fin de fonction debug---------------------------------------------------------------------------------------------------------------------------------------------*/



#endif