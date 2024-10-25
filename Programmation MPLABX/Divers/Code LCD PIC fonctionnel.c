#include <xc.h>
#include <stdlib.h>
#include <string.h>
#include "liblcd.h"

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)

#define _XTAL_FREQ 8000000



#define RS PORTDbits.RD0
#define RW PORTDbits.RD1
#define EN PORTDbits.RD2





void lcd_data(unsigned char data)           //fonction d'envoie des données à l'écran, celles-ci dépende de ce que l'on écrit
{
   
PORTC = data;
RS = 1;
RW = 0;
EN = 1;
__delay_ms(5);
EN = 0;
}

void lcd_cursor (unsigned char ligne,unsigned char colonne)         //fonction a appeler avant d'écrire dans la fonction print(sans centrage auto) pour définir la ligne d'écriture
{
    unsigned char cmd;
    switch (colonne)
    {
    case 0 : 
        cmd= 0x80 | ligne;
    case 1 : 
        cmd = 0xC0 | ligne;
    }

    PORTC = cmd;
    RS = 0;
    RW = 0;
    EN = 1;
    __delay_ms(5);
    EN = 0;
}

void lcd_print (const unsigned char *str)           //fonction pour écrire
{
    unsigned char i;
    int num = strlen(str);

        for (i=0;i<num;i++)
        {
        lcd_data(str[i]);
        }
}



void lcd_initialisation()   //fonction d'initialisation de l'écran à appeler au debut de la fonction main
{
     PORTC = 0x38;
    RS = 0;
    RW = 0;
    EN = 1;
    __delay_ms(5);
    EN = 0;
    
      PORTC = 0x06;
    RS = 0;
    RW = 0;
    EN = 1;
    __delay_ms(5);
    EN = 0;
   
      PORTC = 0x0C;
    RS = 0;
    RW = 0;
    EN = 1;
    __delay_ms(5);
    EN = 0;
    
     PORTC = 0x01;
    RS = 0;
    RW = 0;
    EN = 1;
    __delay_ms(5);
    EN = 0;

    //0x80 = 1er lig 1er col / 0x8F = 16eme lig , 1er col
    //0xC0 = 1er lig 2eme col / 0xCF = 16eme lig, 2eme col
}

void lcd_printcentrer (const unsigned char *car,int col)     //fonction pour écrire avec un centrage automatique de la ligne
{
 unsigned char i;
    int num = strlen(car);
    int lig = (16-strlen(car))/2;
    lcd_cursor (lig,col);
        for (i=0;i<num;i++)
        {
        lcd_data(car[i]);
        }
}

void lcd_clear()            //fonction éffacement de l'affichage des 2 colonnes
{
    lcd_cursor(0,0);
    lcd_print("                ");
    lcd_cursor(0,1);
    lcd_print("                ");
}

void lcd_clear0()           //fonction éffacement de l'affichage de la colonne 0
{
    lcd_cursor(0,0);
    lcd_print("                ");
}

void lcd_clear1()           //fonction éffacement de l'affichage de la colonne 1
{
    lcd_cursor(0,1);
    lcd_print("                ");
}