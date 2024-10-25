#ifndef Modellib_h
#define Modellib_h
#include "Arduino.h"

class exemple 
{
	public : 
		exemple(int capteur,int boutton);
		void exemple_init();
		void exemple::codeSource();


	private :
		const int _Variable_exemple1 = 1024;
		float _Variable_exemple2 = 0.0048828125;
		long int _Variable_exemple3;
		int _Variable_exemple4;
		int _Variable_exemple5;
};

		void FonctionExemple1(String affichage,byte col);
		void FonctionExemple2();

#endif