#include "LCD_16F.h"


void lcd_clear()            //fonction �ffacement de l'affichage des 2 colonnes
{
    lcd_cursor(0,0);
    lcd_print("                ");
    lcd_cursor(0,1);
    lcd_print("                ");
}

void lcd_clear0()           //fonction �ffacement de l'affichage de la colonne 0
{
    lcd_cursor(0,0);
    lcd_print("                ");
}

void lcd_clear1()           //fonction �ffacement de l'affichage de la colonne 1
{
    lcd_cursor(0,1);
    lcd_print("                ");
}

void lcd_printcentrer (const char *car,int col)     //fonction pour �crire avec un centrage automatique de la ligne
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

void lcd_initialisation()   //fonction d'initialisation de l'�cran � appeler au debut de la fonction main
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

void lcd_print (const char *str)           //fonction pour �crire
{
    unsigned char i;
    int num = strlen(str);

        for (i=0;i<num;i++)
        {
        lcd_data(str[i]);
        }
}


void lcd_data(unsigned char data)           //fonction d'envoie des donn�es � l'�cran, celles-ci d�pende de ce que l'on �crit
{
   
PortLCD = data;
RS = 1;
EN = 1;
__delay_ms(5);
EN = 0;
}

void lcd_cursor (unsigned char ligne,unsigned char colonne)         //fonction a appeler avant d'�crire dans la fonction print(sans centrage auto) pour d�finir la ligne d'�criture
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