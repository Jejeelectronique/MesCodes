/* 
 * File:   LCD_16F.h
 * Author: jerry
 *
 * Created on 21 mars 2024, 12:59
 */

#ifndef _LCD__16F_H
#define	_LCD__16F_H

#ifdef	__cplusplus
extern "C" {
#endif
#ifdef	__cplusplus
}
#endif

#include <xc.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define PortLCD PORTD
#define IOstateLCD TRISD
#define RS PORTAbits.RA0
#define EN PORTAbits.RA1
#define _XTAL_FREQ 16000000
#define TimerDelay 100
#define delayLCD (__delay_us(TimerDelay))
#define LongdelayLCD (__delay_us(TimerDelay))

typedef struct lcd1602{
    void (*print)(unsigned char str[17]);
    void (*print_centrer)(const char car[17], int);
    void (*set_cursor)(unsigned char,unsigned char);
    void (*clear)();
    void (*clear0)();
    void (*clear1)();
}lcd1602;


void lcd_printcentrer (const char car[17],int col);
lcd1602 lcd_initialisation(lcd1602 *lcd);
void lcd_clear0();
void lcd_clear1();
void lcd_clear();
void lcd_print (unsigned char str[17]);
void lcd_cursor (unsigned char ligne,unsigned char colonne);
void lcd_data(unsigned char data[17]);


#endif	/* LCD_16F_H */

