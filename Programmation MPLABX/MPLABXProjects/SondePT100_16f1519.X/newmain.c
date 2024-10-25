#include "Config.h"
#include "LCD8bits.h"
#include "TraitementsTemps.h"

#define LED LATAbits.LATA2

#define BtnFlagState INTCONbits.IOCIF      //1 = Interrupt occurs      0 = no occurs

//void __interrupt() ISR(void);
lcd1602 lcd;

volatile CelFar tempMode = Celsius;


int main (void)
{

    lcd_initialisation(&lcd);
    
    ANSELA = 0x00;
    ANSELB = 0x10;
    ANSELD = 0x00;
   
    TRISA = 0xF8;
    TRISB = 0xDF;
    TRISD = 0x00;
    
    while(1)
    {
        lcd_printcentrer("a",1);
    }
    

    init_ADC();
    init_interrupt();
    
    LED = 0;
    IOCIF = 0x00;
    
    while(1)
    {
        lcd.print_centrer("Temperature",0);
        valbrut = (lectureTemp() - offset_can);
        facteur = accroissement(bitcan/(bitcan - valbrut));
        convValBrutTemp = (int)(valbrut / facteur);
        convValBrutTempF = (convValBrutTemp * 1.8) + 32;

        switch(tempMode)
        {
            case Celsius :
            lcd.clear1();
            lcd.set_cursor(0,1);
            lcd.print("Celsius"); 

            lcd.set_cursor(10,1);
            lcd.print(&convValBrutTemp);

            break;

            case Farhen :

            lcd.clear1();
            lcd.set_cursor(0,1);
            lcd.print("Farhenheit");           
            lcd.set_cursor(12,1);
            lcd.print_numeric(convValBrutTempF);
            
            break;
        
        }
         
    }
   
}




/* ------------------------------------------------------------------------------ */

    int lectureTemp()
    {
        ADCON0bits.ADON = 1;    //Active l'ADC
        ADCON0bits.CHS = 0b01011;   // Selectrion la broche RB4 pour l'ADC
        ADCON0bits.GO = 1;  //démarre la conversion
       
        while (ADCON0bits.GO);  //attend la fin de la conversion
        ADCON0bits.ADON = 0;    //désactive l'ADC

        return ((ADRESH << 8) | ADRESL);    //return le résultat des reg 8 bits H et L de l'ADC en 16 Bits dans un int
    }
    
    
void __interrupt() ISR(void)
{   
    LED ^= 1;
    if (tempMode)
        tempMode = Celsius;
    else
        tempMode = Farhen;
    IOCBFbits.IOCBF5 = 0;
}

