#ifndef Sonde2WIRE_h
#define Sonde2WIRE_h



#include "Arduino.h"
#include <LiquidCrystal.h>

class twoWire 
{
	public : 
		twoWire(int capteur,int boutton);
		void twoWire_init();
		void twoWire::codeSource();


	private :
		int _celsfar = 0;
		const int _Vpin = 5;
		const int _bitcan = 1024;
		float _CapV = 0.0048828125;
		long int _valbrut;
		const int _Vref = 0;
		int _capboutton;
		int _tempC;
		int _tempF;
		int _capteur;
		int _boutton;	
		void print_centrage_16(String affichage,byte col);
		void lcdclear();
};






#endif