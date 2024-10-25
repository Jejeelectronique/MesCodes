#include "LCDPIC16F877.h"


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

void lcd_printcentrer (const char car[17],int col)     //fonction pour �crire avec un centrage automatique de la ligne
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

lcd1602 lcd_initialisation(lcd1602 *lcd)   //fonction d'initialisation de l'�cran � appeler au debut de la fonction main
{
    lcd = malloc(sizeof(*lcd));
    if(lcd == NULL)
        exit(EXIT_FAILURE);
    
    lcd->print = lcd_print;
    lcd->print_centrer = lcd_printcentrer;
    lcd->set_cursor = lcd_cursor;
    lcd->clear = lcd_clear;
    lcd->clear0 = lcd_clear0;
    lcd->clear1 = lcd_clear1;
    
     PortLCD = 0x38;
    RS = 0;
    EN = 1;
    delayLCD;
    EN = 0;
    
      PortLCD = 0x06;
    RS = 0;
    EN = 1;
    delayLCD;
    EN = 0;
   
      PortLCD = 0x0C;
    RS = 0;
    EN = 1;
    delayLCD;
    EN = 0;
    
     PortLCD = 0x01;
    RS = 0;
    EN = 1;
    delayLCD;
    EN = 0;
    
    return *lcd;
}

void lcd_print (unsigned char str[17])           //fonction pour �crire
{
    int num = 0;
    unsigned char i;
    
    for (int a = 0; a < 18 ; a++)
    {
         if(str[i] == '\0')
             break;
         num++;
    }

        for (i=0;i<num;i++)
        {
        lcd_data(str[i]);
        }
    
}


void lcd_data(unsigned char data[17])           //fonction d'envoie des donn�es � l'�cran, celles-ci d�pende de ce que l'on �crit
{
   
PortLCD = data;
RS = 1;
EN = 1;
delayLCD;
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
    delayLCD;
    EN = 0;
}