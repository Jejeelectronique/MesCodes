#include <xc.h>
#include "p18cxxx.h"
//#include "LCDPIC16F877.h"
#include "LCD_PT100_PIC16F1519.h"

#pragma config FOSC = ECH       // Oscillator Selection (ECH, External Clock, High Power Mode (4-20 MHz): device clock supplied to CLKIN pin)
#pragma config WDTE = OFF        // Watchdog Timer Enable (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = OFF       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF        // Internal/External Switchover (Internal/External Switchover mode is enabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config VCAPEN = OFF     // Voltage Regulator Capacitor Enable bit (VCAP pin function disabled)
#pragma config STVREN = OFF     // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will not cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)


#define Capteur PORTBbits.RB1
#define _XTAL_FREQ 16000000
#define PortLCD PORTD
#define PinTemp RB4
#define SwitchBtn PORTBbits.RB5

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

lcd1602 lcd;

int main(void)
{
    TRISA = 0x00;
    ANSELA = 0x00;
    TRISD = 0x00;
    ANSELD = 0x00;
    lcd = lcd_initialisation(&lcd);  
    while(1)
    {
        lcd.set_cursor(0,0);
        lcd.print("va");
        lcd.print_centrer("salut",1);
    }
}