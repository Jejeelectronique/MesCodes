#ifndef TraitementsTemps_H
#define	TraitementsTemps_H
#include "Config.h"
#include <stdlib.h>

#ifdef	__cplusplus
extern "C" {
#endif
    
#define V_cap 3.72
#define bitcan 1023
#define Vmax_can 5
#define capV 0.0048828125
#define offset_can (V_cap * bitcan/ Vmax_can)
    
typedef volatile enum CelFar{
    Celsius,
    Farhen
}CelFar;

typedef enum Bool{
    false,
    true
}Bool;


int lectureTemp();


float valbrut;
float facteur;

int convValBrutTemp = 0;
int convValBrutTempF = 0;


//void init_interrupt();
void init_ADC();
void init_interrupt();

void ConvManuel(int data_numerique, char *data);
void ToLower(char *str);
void ToUpper(char *str);

float accroissement(int exp);
#endif