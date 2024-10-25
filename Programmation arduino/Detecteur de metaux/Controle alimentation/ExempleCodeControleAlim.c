#include "alim.h"



alimentation arduinoNano(8,A3);


void setup() 
{
  arduinoNano.alimentation_init();
}

void loop() 
{
  arduinoNano.stop_alimentation(3);
}

