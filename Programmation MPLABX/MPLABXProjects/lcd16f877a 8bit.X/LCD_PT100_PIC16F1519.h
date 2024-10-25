#ifndef LCD_PT100_PIC16F1519_H
#define LCD_PT100_PIC16F1519_H

#ifdef __cplusplus
extern "C" {
#endif

#include <xc.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define PortLCD PORTD
#define IOstateLCD TRISD
#define RS PORTAbits.RA0
#define EN PORTAbits.RA1
#define _XTAL_FREQ 16000000
#define ScreenDelayFunction 100
#define LCDdelay (__delay_us(ScreenDelayFunction))

#define ch_Offset '0'
#define endChar '\0'
#define Gap_Upper_Lower 32
#define BeginUpper 65
#define EndUpper 90
#define BeginLower 97
#define EndLower 122


typedef struct lcd1602 {
    void (*print)(char str[17]);
    void (*print_centrer)(char car[17], char col);
    void (*set_cursor)(char ligne,char colonne);
    void (*print_numeric)(int);
    void (*clear)();
    void (*clear0)();
    void (*clear1)();
} lcd1602;

void lcd_printcentrer (char car[17], char col);
void lcd_clear0();
void lcd_clear1();
void lcd_clear();
void lcd_print (char str[17]);
void lcd_cursor (char ligne, char colonne);
void lcd_data(char data);
void lcd_print_numeric (int str);
void Charge_Pump(char data);

void lcd_initialisationP(lcd1602 **lcd);
lcd1602 lcd_initialisation(lcd1602 *lcd);

void int_to_str(int num, char *str);

#endif /* LCD_16F_H */
