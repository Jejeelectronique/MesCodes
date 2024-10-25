#ifndef Dash_board_h
#define Dash_board_h

#include "Arduino.h"



/*--------------------Classe temperature---------------------------------------------------------------------------------------------------------------------------------------------*/
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
/*--------------------Fin de classe---------------------------------------------------------------------------------------------------------------------------------------------*/






/*--------------------Classe Suralimentation---------------------------------------------------------------------------------------------------------------------------------------------*/
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
/*--------------------Fin de classe---------------------------------------------------------------------------------------------------------------------------------------------*/








/*--------------------Classe pression d'huile---------------------------------------------------------------------------------------------------------------------------------------------*/
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
/*--------------------Fin de classe---------------------------------------------------------------------------------------------------------------------------------------------*/







/*--------------------Classe tachy---------------------------------------------------------------------------------------------------------------------------------------------*/
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
/*--------------------Fin de classe---------------------------------------------------------------------------------------------------------------------------------------------*/







/*--------------------Classe relais---------------------------------------------------------------------------------------------------------------------------------------------*/
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

/*--------------------Fin de classe---------------------------------------------------------------------------------------------------------------------------------------------*/







/*--------------------Classe Airfuel---------------------------------------------------------------------------------------------------------------------------------------------*/
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
/*--------------------Fin de classe---------------------------------------------------------------------------------------------------------------------------------------------*/





/*-------------------fonction debug---------------------------------------------------------------------------------------------------------------------------------------------*/
void debug(int pressionSural, int pressionHuil, int tachy, int temperature,int airFuelRatio);
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/



 //float press_RefSural = 1.5;                                 //  pression limite d'admission en Bar
 //float press_RefHuil = 3.0;                                  //  pression limite de lubrification en Bar*

#endif