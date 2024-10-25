#ifndef serialComs_h
#define serialComs_h

//Bibliotheque de gestion de port série avec protocole ASCII :
// trame de communication:
//   <SyncChar><3 chars commande><parametre, pas de limite de taille><endChar>


#include "Arduino.h"

	typedef enum SerialComStatus{
		TIMEOUT,
		EMPTY,
		IN_PROGRESS,
		DATA_IN
	};

class SerialComs{

	public:
	
	typedef struct SerialComData{
		String command;
		String parameter;
	};
	
	
	SerialComs(HardwareSerial* serialPort_, char syncChar_, char endChar_);
	SerialComStatus manage(); //retourne true si une commande a été détectée. la commande est stockée dans l'objet data
	
	void logMsg(String func, int data);
	void logMsg(String func, String data);
	
	const int TIMEOUT_COM = 200;
	unsigned long int timeOutCom;
	bool dataAvailable = false;
	SerialComData dataSer;
	char syncChar;
	char endChar;
	String bufferRx = "";
	HardwareSerial* serialPort;
	String oldBuffer;
	
	private:
	
	SerialComStatus traitement();
};




#endif