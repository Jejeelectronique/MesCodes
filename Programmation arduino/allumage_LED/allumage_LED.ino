
#include <stdio.h>
#define LED 3


void setup() {

Serial.begin(9600);
pinMode(LED , OUTPUT);
  

}

void loop() {

digitalWrite(LED , HIGH);
delay(1000);
digitalWrite(LED , LOW);
delay(1000);


}
