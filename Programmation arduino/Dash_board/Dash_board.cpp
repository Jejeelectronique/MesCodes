#include "Dash_board.h"








/*--------------------Class temperature---------------------------------------------------------------------------------------------------------------------------------------------*/
temperature::temperature(int tempPin)
{
_pinCateurTemp = tempPin;
}

void temperature::temp_init ()
{
	pinMode(_pinCateurTemp,INPUT);
}

float temperature::traitement_temp()
{
  _tempVal = analogRead(_pinCateurTemp);                            //  lecture de la valeur resistive                                
  _Vctn =  _vin/ 1024 * _tempVal;                      
  _Rctn = _Vctn / ((5.0- _Vctn)/ _rs);                        
  _temperature = ((1.0/((log(_Rctn/_r0)/ _excel)+(1.0/2768.0)))-273.15);
  return _temperature;
 }
/*--------------------Fin de class temperature---------------------------------------------------------------------------------------------------------------------------------------------*/










/*--------------------Class Suralimentation---------------------------------------------------------------------------------------------------------------------------------------------*/

suralimentation::suralimentation(int PinpressionSural)
{
	_pinCapteurSuralim = PinpressionSural;
}


void suralimentation::pressionSural_init()
{
	pinMode(_pinCapteurSuralim,INPUT);
}

float suralimentation::traitement_pressionSural()
{
	_lecturePin = analogRead(_pinCapteurSuralim);
	_pressionSural = ((_lecturePin /1023.0) * 5.0);
	return _pressionSural;
}
/*--------------------Fin de class Suralimentation---------------------------------------------------------------------------------------------------------------------------------------------*/













/*--------------------Class pression d'huile---------------------------------------------------------------------------------------------------------------------------------------------*/
huile::huile(int pinCapteurHuile, int pinledPressHuileMin)
{
	_pinCapteurHuile = pinCapteurHuile;
	_pinledPressHuile = pinledPressHuileMin;
}

void huile::pressionHuile_init()
{
	pinMode(_pinCapteurHuile,INPUT);
	pinMode(_pinledPressHuile,OUTPUT);
}

float huile::traitement_huile()
{
	 _lecturePinH = analogRead(_pinCapteurHuile);          //  lecture de la valeur resisitive 
  _pressionHuile = ((_lecturePinH /1023.0) * 5.0);         //  convertion en volts
  _pressionHuile *= 2;                         //  convertion en bars , /=
  return _pressionHuile; 
   
}
/*--------------------Fin de class pression d'huile---------------------------------------------------------------------------------------------------------------------------------------------*/












/*--------------------Class tachy---------------------------------------------------------------------------------------------------------------------------------------------*/
tachy::tachy(int Pintachy)
{
	_pinCapteurTachy = Pintachy;
}

void tachy::tachy_init()
{
	pinMode(_pinCapteurTachy,INPUT);
}

float tachy::traitement_TrsMin()
{
	_lecturePinT = analogRead(_pinCapteurTachy);                     //  lecture de la valeur resisitive 
  _tachy = ((_tachy / 1023 )* 5);                      //  convertion en volts
  _tachy /= (5/20000);
  return _tachy;                      
}
/*--------------------Fin de class tachy---------------------------------------------------------------------------------------------------------------------------------------------*/













/*--------------------Class relais---------------------------------------------------------------------------------------------------------------------------------------------*/
relais::relais(int PinRelais1,int PinRelais2)
{
	_PinRelais1 = PinRelais1;
	_PinRelais2 = PinRelais2;
}


void relais::relais_init()
{
	pinMode(_PinRelais1,OUTPUT);
	pinMode(_PinRelais2,OUTPUT);
}

void relais::TestPressionSural(float pressRefSural,float Valsuralim)
{
	_press_RefSural = pressRefSural;
	_ValSurAlim = Valsuralim;

  if(_ValSurAlim >= _press_RefSural)
    {                         
     digitalWrite(_PinRelais1, HIGH);                                //  conditions d'activation et d'arret du relai1
    }
     else
     {
       digitalWrite(_PinRelais1, LOW);                               //  conditions d'arret du relai1
     }
}

void relais::TestPressionHuile(float pressRefHuile,float ValHuile)
{
	_press_RefHuil = pressRefHuile;
	_ValSurAlim = _ValHuile;

	 if(ValHuile <= _press_RefHuil)
    {
     digitalWrite(_PinRelais2, LOW);                                 //  conditions d'arret du relai2  
    }
     else
     {
      digitalWrite(_PinRelais2, HIGH);                               //  conditions d'activation du relai2
     }
}
/*--------------------Fin de class relais---------------------------------------------------------------------------------------------------------------------------------------------*/














/*--------------------Class airFuel---------------------------------------------------------------------------------------------------------------------------------------------*/
airFuel::airFuel(int oxygenPin)
{
	_pinOxygen = oxygenPin;
}


void airFuel::airFuel_init()
{
	pinMode(_pinOxygen,INPUT);
}

float airFuel::traitement_airFuel()
{
	_oxygenVolts = analogRead(_pinOxygen) * 5.0 / 1023.0;
  _airFuelRatio = 14.7 * _oxygenVolts / (2.0 - _oxygenVolts);
  return _airFuelRatio;                      
}
/*--------------------Fin de class airFuel---------------------------------------------------------------------------------------------------------------------------------------------*/















/*--------------------Fonction debug---------------------------------------------------------------------------------------------------------------------------------------------*/
void debug(float pressionSural, float pressionHuil, float tachy, float temperature,float airFuelRatio)
	{
		Serial.print("Temperature:");
  	Serial.print(temperature);
  	Serial.println(" °C");
  	Serial.println();
  	delay(2000);

  		
  	Serial.print("Pression Suralimentation:");
  	Serial.print(pressionSural);
  	Serial.println(" Bars");
  	Serial.println();
  	delay(3000);
  
		Serial.print("Pression d'huile:");
		Serial.print(pressionHuil);
		Serial.println(" Bars");
		Serial.println();
		delay(3000);

		Serial.print("Regime:");
		Serial.print(tachy);
		Serial.print( " tr/mn");
		Serial.println();
		delay(200);

		Serial.print("Ratio Air/Fuel:");
    Serial.print(airFuelRatio);
	}
	/*--------------------Fin de fonction debug---------------------------------------------------------------------------------------------------------------------------------------------*/