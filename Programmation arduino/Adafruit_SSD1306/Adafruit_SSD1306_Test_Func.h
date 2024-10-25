#ifndef Adafruit_SSD1306_Test_Func_h
#define Adafruit_SSD1306_Test_Func_h

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define XPOS   0 // Indexes into the 'icons' array in function below
#define YPOS   1
#define DELTAY 2

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define NUMFLAKES     3 // Number of snowflakes in the animation example

static const unsigned char PROGMEM logo_bmp[] =
{ 0b00000000, 0b11000000,
  0b00000001, 0b11000000,
  0b00000001, 0b11000000,
  0b00000011, 0b11100000,
  0b11110011, 0b11100000,
  0b11111110, 0b11111000,
  0b01111110, 0b11111111,
  0b00110011, 0b10011111,
  0b00011111, 0b11111100,
  0b00001101, 0b01110000,
  0b00011011, 0b10100000,
  0b00111111, 0b11100000,
  0b00111111, 0b11110000,
  0b01111100, 0b11110000,
  0b01110000, 0b01110000,
  0b00000000, 0b00110000 };

extern Adafruit_SSD1306 display;

/*
void initialisationClasse(Adafruit_SSD1306 &instance)
Adafruit_SSD1306 *display;
*/

void testdrawline();
void testdrawrect();
void testfillrect();
void testdrawcircle();
void testfillcircle();
void testdrawroundrect();
void testfillroundrect();
void testdrawtriangle();
void testfilltriangle();
void testdrawchar();
void testdrawstyles();
void testscrolltext();
void testdrawbitmap();
void testanimate(const uint8_t *bitmap, uint8_t w, uint8_t h);
void initialisationClasse(char& instance);


#endif
