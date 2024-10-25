#include "LCD_PT100_PIC16F1519.h"


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

void lcd_printcentrer (const char *car,int col)     //fonction pour écrire avec un centrage automatique de la ligne
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

void lcd_initialisation()   //fonction d'initialisation de l'écran à appeler au debut de la fonction main
{
     PortLCD = 0x38;
    RS = 0;
    EN = 1;
    __delay_ms(5);
    EN = 0;
    
      PortLCD = 0x06;
    RS = 0;
    EN = 1;
    __delay_ms(5);
    EN = 0;
   
      PortLCD = 0x0C;
    RS = 0;
    EN = 1;
    __delay_ms(5);
    EN = 0;
    
     PortLCD = 0x01;
    RS = 0;
    EN = 1;
    __delay_ms(5);
    EN = 0;
}

void lcd_print (const char *str)           //fonction pour écrire
{
    unsigned char i;
    int num = strlen(str);

        for (i=0;i<num;i++)
        {
        lcd_data(str[i]);
        }
}


void lcd_data(unsigned char data)           //fonction d'envoie des données à l'écran, celles-ci dépende de ce que l'on écrit
{
   
PortLCD = data;
RS = 1;
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
            cmd = 0x80 | ligne;
        break;
        
        case 1 :
           cmd = 0xC0 | ligne; 
        break;    
    }
    

    PortLCD = cmd;
    RS = 0;
    EN = 1;
    __delay_ms(5);
    EN = 0;
}