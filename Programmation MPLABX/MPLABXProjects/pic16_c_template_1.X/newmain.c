sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;
sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;
// Fin de connection

void main()
{
TRISB = 0;
PORTB = 0xFF;
TRISB = 0xff;
/* Configurer E/S du portB comme numériques*/
//ANSELH = 0;
//ANSEL = 0;
Lcd_Init(); // Initialiser LCD
Lcd_Cmd(_LCD_CLEAR); // Effacer un texte sur l?ecrant LCD
Lcd_Cmd(_LCD_CURSOR_OFF); // Curseur est en off
Lcd_Out(1,2,"-- ABONNE TOI A -- "); // Ecrire le texte sur la 1ère ligne
Lcd_Out(2,1,"Tech inov237_LCD_4b"); // Ecrire le texte sur la 2ème ligne
}