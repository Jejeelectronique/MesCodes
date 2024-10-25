
#ifndef 7SEG_H
#define 7SEG_H

#include <xc.h>
#include <stdint.h>

#define C1   PORTCbits.RC0    //La colonne 1 est connectée au pin RC0 du PORTC
#define C2   PORTCbits.RC1    //La colonne 2 est connectée au pin RC1 du PORTC
#define C3   PORTCbits.RC2    //La colonne 3 est connectée au pin RC2 du PORTC

#define LA   PORTCbits.RC3    //La ligne 1 est connectée au pin RC3 du PORTC
#define LB   PORTCbits.RC4    //La ligne 2 est connectée au pin RC4 du PORTC
#define LC   PORTCbits.RC5    //La ligne 3 est connectée au pin RC5 du PORTC
#define LD   PORTCbits.RC6    //La ligne 4 est connectée au pin RC6 du PORTC

#define SW PORTDbits.RD7      //Le switch est connecter au pin de RD7 du PORTD
#define RESET PORTCbits.RC7   // Le Reset est relier au pin RC7 du PORTC



void clavier();
void test();
void affichage();



#endif	/* 7SEG_H */

