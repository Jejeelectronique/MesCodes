/*
* File: main.c
* Author: Khaled Magdy
* LAB Number: 28
* LAB Name: Writing Text To LCD
*/
#include <xc.h>
#define _XTAL_FREQ 48000000
 
#define LCD_EN_Delay 500
#define LCD_DATA_PORT_D TRISB
#define LCD_RS_D TRISB5
#define LCD_EN_D TRISB4
#define RS RB5
#define EN RB4
#define D4 RB0
#define D5 RB1
#define D6 RB2
#define D7 RB3
//==========================================
//-----[ Prototypes For All Functions ]-----
void LCD_Init();
void LCD_Clear();
void LCD_SL();
void LCD_SR();
void LCD_CMD(unsigned char);
void LCD_DATA(unsigned char);
void LCD_Set_Cursor(unsigned char, unsigned char);
void LCD_Write_Char(char);
void LCD_Write_String(char*);
//------------------------------------------
void main(void) {
 
  LCD_Init();
  LCD_Clear();
  LCD_Set_Cursor(1,1);
  LCD_Write_String("Khaled Magdy\0");
  LCD_Set_Cursor(2,1);
  LCD_Write_String(" DeepBlue\0");
  while(1)
  {
    
  }
  return;
}
//============================================
//-----[ Alphanumeric LCD 16x2 Routines ]-----
void LCD_DATA(unsigned char Data)
{
  if(Data & 1)
    D4 = 1;
  else
    D4 = 0;
  if(Data & 2)
    D5 = 1;
  else
    D5 = 0;
  if(Data & 4)
    D6 = 1;
  else
    D6 = 0;
  if(Data & 8)
    D7 = 1;
  else
    D7 = 0;
}
void LCD_CMD(unsigned char CMD)
{
  // Select Command Register
  RS = 0;
  // Move The Command Data To LCD
  LCD_DATA(CMD);
  // Send The EN Clock Signal
  EN = 1;
  __delay_us(LCD_EN_Delay);
  EN = 0;
}
void LCD_Clear()
{
  LCD_CMD(0);
  LCD_CMD(1);
}
void LCD_Set_Cursor(unsigned char r, unsigned char c)
{
  unsigned char Temp,Low4,High4;
  if(r == 1)
  {
    Temp = 0x80 + c - 1; //0x80 is used to move the cursor
    High4 = Temp >> 4;
    Low4 = Temp & 0x0F;
    LCD_CMD(High4);
    LCD_CMD(Low4);
  }
  if(r == 2)
  {
    Temp = 0xC0 + c - 1;
    High4 = Temp >> 4;
    Low4 = Temp & 0x0F;
    LCD_CMD(High4);
    LCD_CMD(Low4);
  }
}
void LCD_Init()
{
  // IO Pin Configurations
  LCD_DATA_PORT_D = 0x00;
  LCD_RS_D = 0;
  LCD_EN_D = 0;
  // The Init. Procedure As Described In The Datasheet
  LCD_DATA(0x00);
  __delay_ms(30);
  __delay_us(LCD_EN_Delay);
  LCD_CMD(0x03);
  __delay_ms(5);
  LCD_CMD(0x03);
  __delay_us(150);
  LCD_CMD(0x03);
  LCD_CMD(0x02);
  LCD_CMD(0x02);
  LCD_CMD(0x08);
  LCD_CMD(0x00);
  LCD_CMD(0x0C);
  LCD_CMD(0x00);
  LCD_CMD(0x06);
}
void LCD_Write_Char(char Data)
{
  char Low4,High4;
  Low4 = Data & 0x0F;
  High4 = Data & 0xF0;
  RS = 1;
  LCD_DATA(High4>>4);
  EN = 1;
  __delay_us(LCD_EN_Delay);
  EN = 0;
  __delay_us(LCD_EN_Delay);
  LCD_DATA(Low4);
  EN = 1;
  __delay_us(LCD_EN_Delay);
  EN = 0;
  __delay_us(LCD_EN_Delay);
}
void LCD_Write_String(char *str)
{
  int i;
  for(i=0;str[i]!='\0';i++)
    LCD_Write_Char(str[i]);
}
void LCD_SL()
{
  LCD_CMD(0x01);
  LCD_CMD(0x08);
}
void LCD_SR()
{
  LCD_CMD(0x01);
  LCD_CMD(0x0C);
}
