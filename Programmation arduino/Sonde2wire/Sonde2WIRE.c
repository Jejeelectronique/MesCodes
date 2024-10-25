
#include <stdio.h>
#include <Wire.h>
#include "Sonde2WIRE.h"


#define Capteur A0
#define boutton 10


twoWire moncapteur(Capteur,boutton);


void setup() {
  
moncapteur.twoWire_init();

}

void loop() {

moncapteur.codeSource();

}




