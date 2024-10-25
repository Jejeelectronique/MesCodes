#include <Arduino.h>
#include "serialComs.h"


	SerialComs::SerialComs(HardwareSerial* serialPort_, char syncChar_, char endChar_){
		serialPort=serialPort_;
		syncChar=syncChar_;
		endChar=endChar_;
		
	}
	
	SerialComStatus SerialComs::manage(){
		  SerialComStatus returnCode=EMPTY;
		  char incomingByte;
			//Serial.println("entree event: " + String(millis()));
			while (serialPort->available()) {
				incomingByte = serialPort->read();
				bufferRx += incomingByte;
				timeOutCom = millis();	
			}
		
		
	    if (bufferRx.length() > 0) {
			returnCode=traitement();
		}
	return returnCode;
	}
	
	void SerialComs::logMsg(String func, int data){
		logMsg(func,String(data));
	}
	
	void SerialComs::logMsg(String func, String data){
		serialPort->print(syncChar+ func + data + endChar);
	}
	
		
	SerialComStatus SerialComs::traitement(){
		
	  String trame;
	  int indexSeparator;
	  int indexStart = 0;
	  int indexEnd = 0;
	  SerialComStatus returnCode=IN_PROGRESS;
	  //Serial.println("dans traitement: "+String(millis()));
	  // gestion du timeout
	  if ((millis() - timeOutCom) > TIMEOUT_COM) {
		
		returnCode= TIMEOUT; // Une donnée présente dans le buffer ne peut pas être traitée et est éliminée.
		oldBuffer=bufferRx;
		bufferRx = "";
	  }

	  indexStart = bufferRx.indexOf(syncChar);
	  if (indexStart > -1) {
		indexEnd = bufferRx.indexOf(endChar);
		if (indexEnd > -1) { // on &a la fin et le debut
		  trame = bufferRx.substring(indexStart, indexEnd);
		  //Serial.println(trame);
		  dataSer.command = trame.substring(1, 4);
		  dataSer.parameter = trame.substring(4);
		  bufferRx.remove(indexStart, indexEnd - indexStart + 1);
		  returnCode=DATA_IN;
		  //Serial.println("<"+fonction+">");


		}
	  }
	return returnCode;
}


