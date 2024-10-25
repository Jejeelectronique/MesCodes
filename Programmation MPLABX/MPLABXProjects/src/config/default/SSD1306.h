#ifndef SSD1306_H
#define SSD1306_H

#ifdef  __cplusplus
extern "C" {
#endif
    
#include <stdio.h>    
#include <xc.h> 
#include <string.h>
#include "definitions.h"                // SYS function prototypes
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#ifndef I2C_adress
#define I2C_adress 0x3C     //0011 1100 << 1 = 0111 100(R/W)
#endif
    
#define SIZE_BUFFER_I2C_TX 8


// Ecran 128x32
#define WIDTH 128 ///< DEPRECATED: width w/SSD1306_128_32 defined
#define HEIGHT 32 ///< DEPRECATED: height w/SSD1306_128_32 defined

#define SSD1306_BLACK 0   ///< Draw 'off' pixels
#define SSD1306_WHITE 1   ///< Draw 'on' pixels
#define SSD1306_INVERSE 2 ///< Invert pixels

#define SSD1306_MEMORYMODE 0x20          ///< See datasheet
#define SSD1306_COLUMNADDR 0x21          ///< See datasheet
#define SSD1306_PAGEADDR 0x22            ///< See datasheet
#define SSD1306_SETCONTRAST 0x81         ///< See datasheet
#define SSD1306_CHARGEPUMP 0x8D          ///< See datasheet
#define SSD1306_SEGREMAP 0xA0            ///< See datasheet
#define SSD1306_DISPLAYALLON_RESUME 0xA4 ///< See datasheet
#define SSD1306_DISPLAYALLON 0xA5        ///< Not currently used
#define SSD1306_NORMALDISPLAY 0xA6       ///< See datasheet
#define SSD1306_INVERTDISPLAY 0xA7       ///< See datasheet
#define SSD1306_SETMULTIPLEX 0xA8        ///< See datasheet
#define SSD1306_DISPLAYOFF 0xAE          ///< See datasheet
#define SSD1306_DISPLAYON 0xAF           ///< See datasheet
#define SSD1306_COMSCANINC 0xC0          ///< Not currently used
#define SSD1306_COMSCANDEC 0xC8          ///< See datasheet
#define SSD1306_SETDISPLAYOFFSET 0xD3    ///< See datasheet
#define SSD1306_SETDISPLAYCLOCKDIV 0xD5  ///< See datasheet
#define SSD1306_SETPRECHARGE 0xD9        ///< See datasheet
#define SSD1306_SETCOMPINS 0xDA          ///< See datasheet
#define SSD1306_SETVCOMDETECT 0xDB       ///< See datasheet

#define SSD1306_SETLOWCOLUMN 0x00  ///< Not currently used
#define SSD1306_SETHIGHCOLUMN 0x10 ///< Not currently used
#define SSD1306_SETSTARTLINE 0x40  ///< See datasheet

#define SSD1306_EXTERNALVCC 0x01  ///< External display voltage source
#define SSD1306_SWITCHCAPVCC 0x02 ///< Gen. display voltage from 3.3V

#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26              ///< Init rt scroll
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27               ///< Init left scroll
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29 ///< Init diag scroll
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A  ///< Init diag scroll
#define SSD1306_DEACTIVATE_SCROLL 0x2E                    ///< Stop scroll
#define SSD1306_ACTIVATE_SCROLL 0x2F                      ///< Start scroll
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3             ///< Set scroll range

#define ssd1306_swap(a, b)                                                     \
  (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b))) ///< No-temp-var swap operation

#ifndef pgm_read_byte
#define pgm_read_byte(addr) (*(const unsigned char *)(addr))
#endif
#ifndef pgm_read_word
#define pgm_read_word(addr) (*(const unsigned short *)(addr))
#endif
#ifndef pgm_read_dword
#define pgm_read_dword(addr) (*(const unsigned long *)(addr))
#endif
#ifndef pgm_read_byte
#define pgm_read_byte(addr) (*(const unsigned char *)(addr))
#endif
#ifndef pgm_read_word
#define pgm_read_word(addr) (*(const unsigned short *)(addr))
#endif
#ifndef pgm_read_dword
#define pgm_read_dword(addr) (*(const unsigned long *)(addr))
#endif
#if !defined(__INT_MAX__) || (__INT_MAX__ > 0xFFFF)
#define pgm_read_pointer(addr) ((void *)pgm_read_dword(addr))
#else
#define pgm_read_pointer(addr) ((void *)pgm_read_word(addr))
#endif


//#define  TRANSACTION_END Wire.setClock(restoreClk)
//#define  TRANSACTION_START Wire.setClock(wireCLK)


void ssd1306_command1(uint8_t c);
void ssd1306_commandList(const uint8_t *c, uint8_t n);
void ssd1306_command(uint8_t c);
uint8_t SSD1306_begin();
void SSD1306_clearDisplay();
void SSD1306_drawPixel(int16_t x, int16_t y, uint16_t color);
void SSD1306_drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
void SSD1306_drawFastHLineInternal(int16_t x, int16_t y, int16_t w, uint16_t color);
void SSD1306_drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
void SSD1306_drawFastVLineInternal(int16_t x, int16_t __y, int16_t __h, uint16_t color);
uint8_t SSD1306_getPixel(int16_t x, int16_t y);
uint8_t *SSD1306_getBuffer();
void SSD1306_display();
void SSD1306_startscrollright(uint8_t start, uint8_t stop);
void SSD1306_startscrolldiagright(uint8_t start, uint8_t stop);
void SSD1306_startscrolldiagleft(uint8_t start, uint8_t stop);
void SSD1306_invertDisplay(uint8_t i);
void SSD1306_startscrollleft(uint8_t start, uint8_t stop);
void SSD1306_drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);

void testdrawline();
void SSD1306_writeLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
//void writePixel(int16_t x, int16_t y, uint16_t color);

void setRotation(uint8_t x);
uint8_t getRotation();


 /*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/   
#endif  /* SSD1306_H */