#include "LCD_PT100_PIC16F1519.h"
#include <stdio.h>
#include <string.h>
#include <time.h>


void lcd_print(char str[17]) 
{
    unsigned int a = 0;
    unsigned int numeric = 0;
    unsigned int Nbnum = 0;
    char data[17] = {[0] = 0, [16] = '\0'};

    for(a = 0; a < 18; a++) {
        if(str[a] == endChar)
            break;
        Nbnum += str[a];
    }
    
    switch (a) {
        case 17:
            int_to_str(Nbnum , data);
            numeric = strlen(data);
            for(int i = 0; i < numeric; i++) {
                lcd_data(data[i]); 
            }
            break;
        default:
            for (int i = 0; i < a; i++) 
            {
                lcd_data(str[i]);
            }
            break;
    }
}


void lcd_print_numeric(int str) 
{
    char data[17];
    int_to_str(str, data);
    
    char i;
    int num = (int)strlen(data);

    for (i = 0; i < num; i++) {
        lcd_data(data[i]);
    }
}

void lcd_data(char data) 
{
    PortLCD = data;
    RS = 1;
    EN = 1;
    LCDdelay;
    EN = 0;
}

void lcd_cursor(char ligne, char colonne) 
{
    char cmd;
    switch (colonne) 
    {
        case 0:
            cmd = 0x80 | ligne;
            break;

        case 1:
            cmd = 0xC0 | ligne;
            break;
            
        default:
            cmd = 0x80 | ligne;
            break;    
    }
    Charge_Pump(cmd);
}


void Charge_Pump(char data)
{
    PortLCD = data;
    RS = 0;
    EN = 1;
    LCDdelay;
    EN = 0;
}

void lcd_printcentrer (char car[17], char col) 
{
    char i;
    int num = (int)strlen(car);
    char lig = (16 - strlen(car)) / 2;
    lcd_cursor(lig, col);
    for (i = 0; i < num; i++) {
        lcd_data(car[i]);
    }
}

void lcd_clear() 
{
    lcd_cursor(0,0);
    lcd_print("                ");
    lcd_cursor(0,1);
    lcd_print("                ");
}

void lcd_clear0() 
{
    lcd_cursor(0,0);
    lcd_print("                ");
}

void lcd_clear1() 
{
    lcd_cursor(0,1);
    lcd_print("                ");
}


lcd1602 lcd_initialisation(lcd1602 *lcd) {
    
    lcd = malloc(sizeof(*lcd));
    if(lcd == NULL)
        exit(EXIT_FAILURE);

    lcd->print = lcd_print;
    lcd->print_centrer = lcd_printcentrer;
    lcd->set_cursor = lcd_cursor;
    lcd->print_numeric = lcd_print_numeric;
    lcd->clear = lcd_clear;
    lcd->clear0 = lcd_clear0;
    lcd->clear1 = lcd_clear1;

    Charge_Pump(0x38);
    Charge_Pump(0x06);
    Charge_Pump(0x0C);
    Charge_Pump(0x01);

    return *lcd;
}


 void lcd_initialisationP(lcd1602 **lcd) {
     *lcd = malloc(sizeof(lcd1602));
     if(*lcd == NULL)
         return;

     (*lcd)->print = lcd_print;
     (*lcd)->print_centrer = lcd_printcentrer;
     (*lcd)->set_cursor = lcd_cursor;
     (*lcd)->print_numeric = lcd_print_numeric;
     (*lcd)->clear = lcd_clear;
     (*lcd)->clear0 = lcd_clear0;
     (*lcd)->clear1 = lcd_clear1;

     Charge_Pump(0x38);
     Charge_Pump(0x06);
     Charge_Pump(0x0C);
     Charge_Pump(0x01);
 }


void int_to_str(int num, char *str) 
{
    sprintf(str, "%d", num);
}