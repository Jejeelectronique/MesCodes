#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>
#include <stdio.h>
#include <proc/p32mx250f128b.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "CommI2C.h"
#include "SSD1306.h"

#define I2C_adress 0x3C     //0011 1100 << 1 = 0111 100(R/W)


#define LED_verte_ON (LATB |= 0x8000)  //PORTBbits.RB15
#define LED_rouge_ON (LATB |= 0x4000)  //PORTBbits.RB14
#define LED_OFF (LATB &= ~0xC000)

#define delaysUS 100000

uint32_t MyTimer;
uint32_t LastTimer;

int main ( void )
{
    SYS_Initialize ( NULL );
    PORTB &= 0x7FFF;  
    CORETIMER_Start();
    SSD1306_begin();
    SSD1306_clearDisplay();
    
    //SSD1306_drawLine(45,  10,  22,  42,  0);
   // SSD1306_drawPixel(0,0,0);
    SSD1306_drawFastVLineInternal(10,15,4,0);
    
    while ( true )                                          //Boucle principal du code
    {   
        
        //CORETIMER_DelayMs(1000);

        
        LED_OFF;
        if(Wire.beginTransmission(I2C_adress))
        {
            LED_rouge_ON;
        }
        
        else
        {  
            LED_verte_ON;
        }    
        
        Wire.StopCom();
    }
    
    return ( EXIT_FAILURE );
}


