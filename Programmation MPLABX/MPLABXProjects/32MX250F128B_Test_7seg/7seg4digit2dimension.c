#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

typedef enum {Zero = 0,Un,Deux,Trois,Quatre,Cinq,Six,Sept,Huit,Neuf} Chiffre;
typedef enum {Digit1 = 0,Digit2,Digit3,Digit4} Digits;

#define PrtA 0
#define PrtB 1

void Affichage(Chiffre num, Digits dig);


unsigned char a = 0;
unsigned char digControl = 0;
unsigned int Ctrl = 0;
//                            0    /     1    /     2     /   3     /    4     /    5     /    6     /     7    /     8    /    9
uint32_t Chiffres[10] = {0x000BC008,0x00080008,0x000F4000,0x000E4008,0x000C8008,0x0006C008,0x0007C008,0x00084008,0x000FC008,0x000EC008};  //16Bits MSB PORTA 16Bits LSB PORTB


//                       1    /    2     /    3     /    4     /    5
uint32_t Digi[5] = {0x00102020,0x00002030,0x00102010,0x00100030,0x00102030}; //16Bits MSB PORTA 16Bits LSB PORTB
                           

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    CFGCONbits.IOLOCK = 0;
    CFGCONbits.PMDLOCK = 0;
    
    TRISA = 0xFFE0;         //Config des I/O du portA
    TRISB = 0x1FC7;         //Config des I/O du portB
    
    PORTA = 0xFFFF;
    PORTB = 0xFFFF;
 
    while ( true )
    {
        SYS_Tasks ( );
        
        for (a = 0; a < 10; a++)
    {
    Affichage(a,Ctrl);
    Ctrl++;
    if (Ctrl >= 4)
        Ctrl = 0;
  
    for (int i = 0; i <800000; i++){}
    }

    a=0;
    digControl++;
        
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}

void Affichage(Chiffre num, Digits dig)
{
    PORTA = ((Chiffres[num] >> 16 & 0x0000FFFF) | (Digi[dig] >> 16 & 0x0000FFFF));
    PORTB = ((Chiffres[num] & 0x0000FFFF) | (Digi[dig] & 0x0000FFFF)); 
}

/*******************************************************************************
 End of File
*/

