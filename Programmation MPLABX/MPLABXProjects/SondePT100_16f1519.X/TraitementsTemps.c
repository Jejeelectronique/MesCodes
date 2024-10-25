#include "TraitementsTemps.h"

void init_interrupt()
{
    INTCONbits.GIE = 1;
    INTCONbits.IOCIE = 1;
    OPTION_REGbits.INTEDG = 1;
    IOCBPbits.IOCBP5 = 1;
}

void init_ADC()
{
    ADCON1bits.ADPREF = 0b00; // R�f�rence de tension VDD
    ADCON1bits.ADCS = 0b010; // Horloge de conversion Fosc/32
    ADCON1bits.ADFM = 1; // R�sultat justifi� � droite
    ADCON0bits.ADON = 0; // Activer l'ADC
}

float accroissement(int exp)
{
    float exposant = 1;
    if(exp > 2)
    {
        exposant = 2.71828;
        for(int i = 0 ; i <= exp ; i++)
            exposant *= exposant;        
    }

    return exposant;
}


/* void int_to_str(int num, char *str) 
{
    sprintf(str, "%d", num);
} */

void ConvManuel(int data_numerique, char *data) 
{
    if(data_numerique < 10) {            
        data[0] = data_numerique + ch_Offset;
        data[1] = 0;
        data[2] = 0; 
    } else if(data_numerique >= 10 && data_numerique < 100) {            
        data[0] = (data_numerique / 10) + ch_Offset;
        data[1] = (data_numerique % 10) + ch_Offset;
        data[2] = 0;
    } else if (data_numerique >= 100 && data_numerique < 1000) {
        data[0] = (data_numerique / 100) + ch_Offset;
        data[1] = ((data_numerique / 10) % 10) + ch_Offset;
        data[2] = (data_numerique % 10) + ch_Offset;
    }
}

void ToUpper(char *str) 
{
    int i = 0;
    while(str[i++] != endChar) {
        if(str[i - 1] > EndUpper)
            str[i - 1] -= Gap_Upper_Lower;
    }
}

void ToLower(char *str) 
{
    int i = 0;
    while(str[i++] != endChar) {
        if(str[i - 1] < BeginLower)
            str[i - 1] += Gap_Upper_Lower;
    }
}