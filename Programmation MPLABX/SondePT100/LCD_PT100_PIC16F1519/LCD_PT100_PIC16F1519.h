/* 
 * File:   LCD_16F.h
 * Author: jerry
 *
 * Created on 21 mars 2024, 12:59
 */

#ifndef LCD_PT100_PIC16F1519_H
#define	LCD_PT100_PIC16F1519_H

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


void lcd_printcentrer (const char *car,int col);
void lcd_initialisation();
void lcd_clear0();
void lcd_clear1();
void lcd_clear();
void lcd_print (const char *str);
void lcd_cursor (unsigned char ligne,unsigned char colonne);
void lcd_data(unsigned char data);



#endif	/* LCD_16F_H */

