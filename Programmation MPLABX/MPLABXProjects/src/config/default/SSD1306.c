#include "SSD1306.h"
#include "CommI2C.h"

#define ssd1306_swap(a, b)                                                     \
  (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b))) ///< No-temp-var swap operation

uint8_t *buffer;
uint32_t restoreClk; ///< Wire speed following SSD1306 transfers
uint8_t contrast; ///< normal contrast setting for this device
uint8_t vccstate = 0x02;
uint32_t wireClk;    ///< Wire speed for SSD1306 transfers
uint8_t rotation;     ///< Display rotation (0 thru 3)  
uint8_t _height;
uint8_t _width;


void ssd1306_command1(uint8_t c) {
    Wire.beginTransmission(I2C_adress);
    Wire.SendData((uint8_t)0x00); // Co = 0, D/C = 0
    Wire.SendData(c);
    Wire.StopCom();
  }


  void ssd1306_commandList(const uint8_t *c, uint8_t n) 
  {
    Wire.beginTransmission(I2C_adress);
    Wire.SendData((uint8_t)0x00); // Co = 0, D/C = 0
    uint16_t bytesOut = 1;
    while (n--) 
    {
      if (bytesOut >= SIZE_BUFFER_I2C_TX) 
      {
        Wire.StopCom();
        Wire.beginTransmission(I2C_adress);
        Wire.SendData((uint8_t)0x00); // Co = 0, D/C = 0
        bytesOut = 1;
      }
      Wire.SendData((uint8_t)(*c++));
      bytesOut++;
    }
    Wire.StopCom();
}
 

 void ssd1306_command(uint8_t c) 
{
  //TRANSACTION_START
  ssd1306_command1(c);
  //TRANSACTION_END
}

void SSD1306_clearDisplay() 
{
  memset(buffer, 0, WIDTH * ((HEIGHT + 7) / 8));
}

// ALLOCATE & INIT DISPLAY -------------------------------------------------

/*!
    @brief  Allocate RAM for image buffer, initialize peripherals and pins.
    @param  vcs
            VCC selection. Pass SSD1306_SWITCHCAPVCC to generate the display
            voltage (step up) from the 3.3V source, or SSD1306_EXTERNALVCC
            otherwise. Most situations with Adafruit SSD1306 breakouts will
            want SSD1306_SWITCHCAPVCC.
    @param  addr
            I2C address of corresponding SSD1306 display (or pass 0 to use
            default of 0x3C for 128x32 display, 0x3D for all others).
            SPI displays (hardware or software) do not use addresses, but
            this argument is still required (pass 0 or any value really,
            it will simply be ignored). Default if unspecified is 0.
    @param  reset
            If true, and if the reset pin passed to the constructor is
            valid, a hard reset will be performed before initializing the
            display. If using multiple SSD1306 displays on the same bus, and
            if they all share the same reset pin, you should only pass true
            on the first display being initialized, false on all others,
            else the already-initialized displays would be reset. Default if
            unspecified is true.
    @param  periphBegin
            If true, and if a hardware peripheral is being used (I2C or SPI,
            but not software SPI), call that peripheral's begin() function,
            else (false) it has already been done in one's sketch code.
            Cases where false might be used include multiple displays or
            other devices sharing a common bus, or situations on some
            platforms where a nonstandard begin() function is available
            (e.g. a TwoWire interface on non-default pins, as can be done
            on the ESP8266 and perhaps others).
    @return true on successful allocation/init, false otherwise.
            Well-behaved code should check the return value before
            proceeding.
    @note   MUST call this function before any drawing or updates!
*/

uint8_t SSD1306_begin()
{
  if ((!buffer) && !(buffer = (uint8_t *)malloc(WIDTH * ((HEIGHT + 7) / 8))))
    return 0;
  SSD1306_clearDisplay();

  static const uint8_t init1[] = {SSD1306_DISPLAYOFF,
                                  SSD1306_SETDISPLAYCLOCKDIV,
                                  0x80, // the suggested ratio 0x80
                                  SSD1306_SETMULTIPLEX};

  ssd1306_commandList(init1, sizeof(init1));
  ssd1306_command1(HEIGHT - 1);

  static const uint8_t init2[] = {SSD1306_SETDISPLAYOFFSET, // 0xD3
                                  0x0,                      // no offset
                                  SSD1306_SETSTARTLINE | 0x0, // line #0
                                  SSD1306_CHARGEPUMP};

  ssd1306_commandList(init2, sizeof(init2));
  ssd1306_command1((vccstate == SSD1306_EXTERNALVCC) ? 0x10 : 0x14);

  static const uint8_t init3[] = {SSD1306_MEMORYMODE, // 0x20
                                  0x00, // 0x0 act like ks0108
                                  SSD1306_SEGREMAP | 0x1,
                                  SSD1306_COMSCANDEC};

  ssd1306_commandList(init3, sizeof(init3));

  uint8_t comPins = 0x02;
  contrast = 0x8F;

  ssd1306_command1(SSD1306_SETCOMPINS);
  ssd1306_command1(comPins);
  ssd1306_command1(SSD1306_SETCONTRAST);
  ssd1306_command1(contrast);

  ssd1306_command1(SSD1306_SETPRECHARGE); // 0xd9
  ssd1306_command1((vccstate == SSD1306_EXTERNALVCC) ? 0x22 : 0xF1);
  static const uint8_t init5[] = {
      SSD1306_SETVCOMDETECT, // 0xDB
      0x40,
      SSD1306_DISPLAYALLON_RESUME, // 0xA4
      SSD1306_NORMALDISPLAY,       // 0xA6
      SSD1306_DEACTIVATE_SCROLL,
      SSD1306_DISPLAYON}; // Main screen turn on
  ssd1306_commandList(init5, sizeof(init5));

  //TRANSACTION_END
  return 1; 
}


// DRAWING FUNCTIONS -------------------------------------------------------

/*!
    @brief  Set/clear/invert a single pixel. This is also invoked by the
            Adafruit_GFX library in generating many higher-level graphics
            primitives.
    @param  x
            Column of display -- 0 at left to (screen width - 1) at right.
    @param  y
            Row of display -- 0 at top to (screen height -1) at bottom.
    @param  color
            Pixel color, one of: SSD1306_BLACK, SSD1306_WHITE or
            SSD1306_INVERSE.
    @return None (void).
    @note   Changes buffer contents only, no immediate effect on display.
            Follow up with a call to display(), or with other graphics
            commands as needed by one's own application.
*/


void SSD1306_drawPixel(int16_t x, int16_t y, uint16_t color) {
  if ((x >= 0) && (x < WIDTH) && (y >= 0) && (y < HEIGHT)) {
    // Pixel is in-bounds. Rotate coordinates if needed.
    switch (getRotation()) 
    {
    case 1:
      ssd1306_swap(x, y);
      x = WIDTH - x - 1;
      break;
    case 2:
      x = WIDTH - x - 1;
      y = HEIGHT - y - 1;
      break;
    case 3:
      ssd1306_swap(x, y);
      y = HEIGHT - y - 1;
      break;
    }
    switch (color) {
    case SSD1306_WHITE:
      buffer[x + (y / 8) * WIDTH] |= (1 << (y & 7));
      break;
    case SSD1306_BLACK:
      buffer[x + (y / 8) * WIDTH] &= ~(1 << (y & 7));
      break;
    case SSD1306_INVERSE:
      buffer[x + (y / 8) * WIDTH] ^= (1 << (y & 7));
      break;
    }
  }
}

/*!
    @brief  Draw a horizontal line. This is also invoked by the Adafruit_GFX
            library in generating many higher-level graphics primitives.
    @param  x
            Leftmost column -- 0 at left to (screen width - 1) at right.
    @param  y
            Row of display -- 0 at top to (screen height -1) at bottom.
    @param  w
            Width of line, in pixels.
    @param  color
            Line color, one of: SSD1306_BLACK, SSD1306_WHITE or SSD1306_INVERSE.
    @return None (void).
    @note   Changes buffer contents only, no immediate effect on display.
            Follow up with a call to display(), or with other graphics
            commands as needed by one's own application.
*/

void SSD1306_drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) 
{
  uint8_t bSwap = 0;
  switch (rotation) {
  case 1:
    // 90 degree rotation, swap x & y for rotation, then invert x
    bSwap = 1;
    ssd1306_swap(x, y);
    x = WIDTH - x - 1;
    break;
  case 2:
    // 180 degree rotation, invert x and y, then shift y around for height.
    x = WIDTH - x - 1;
    y = HEIGHT - y - 1;
    x -= (w - 1);
    break;
  case 3:
    // 270 degree rotation, swap x & y for rotation,
    // then invert y and adjust y for w (not to become h)
    bSwap = 1;
    ssd1306_swap(x, y);
    y = HEIGHT - y - 1;
    y -= (w - 1);
    break;
  }

  if (bSwap)
    SSD1306_drawFastVLineInternal(x, y, w, color);
  else
    SSD1306_drawFastHLineInternal(x, y, w, color);
}

/*!
    @brief  Draw a horizontal line with a width and color. Used by public
   methods drawFastHLine,drawFastVLine
        @param x
                   Leftmost column -- 0 at left to (screen width - 1) at right.
        @param y
                   Row of display -- 0 at top to (screen height -1) at bottom.
        @param w
                   Width of line, in pixels.
        @param color
               Line color, one of: SSD1306_BLACK, SSD1306_WHITE or
   SSD1306_INVERSE.
    @return None (void).
    @note   Changes buffer contents only, no immediate effect on display.
            Follow up with a call to display(), or with other graphics
            commands as needed by one's own application.
*/



void SSD1306_drawFastHLineInternal(int16_t x, int16_t y, int16_t w, uint16_t color) 
{
  if ((y >= 0) && (y < HEIGHT)) { // Y coord in bounds?
    if (x < 0) {                  // Clip left
      w += x;
      x = 0;
    }
    if ((x + w) > WIDTH) { // Clip right
      w = (WIDTH - x);
    }
    if (w > 0) { // Proceed only if width is positive
      uint8_t *pBuf = &buffer[(y / 8) * WIDTH + x], mask = 1 << (y & 7);
      switch (color) {
      case SSD1306_WHITE:
        while (w--) {
          *pBuf++ |= mask;
        };
        break;
      case SSD1306_BLACK:
        mask = ~mask;
        while (w--) {
          *pBuf++ &= mask;
        };
        break;
      case SSD1306_INVERSE:
        while (w--) {
          *pBuf++ ^= mask;
        };
        break;
      }
    }
  }
}

/*!
    @brief  Draw a vertical line. This is also invoked by the Adafruit_GFX
            library in generating many higher-level graphics primitives.
    @param  x
            Column of display -- 0 at left to (screen width -1) at right.
    @param  y
            Topmost row -- 0 at top to (screen height - 1) at bottom.
    @param  h
            Height of line, in pixels.
    @param  color
            Line color, one of: SSD1306_BLACK, SSD1306_WHITE or SSD1306_INVERSE.
    @return None (void).
    @note   Changes buffer contents only, no immediate effect on display.
            Follow up with a call to display(), or with other graphics
            commands as needed by one's own application.
*/


void SSD1306_drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) 
{
  uint8_t bSwap = 0;
  switch (rotation) {
  case 1:
    // 90 degree rotation, swap x & y for rotation,
    // then invert x and adjust x for h (now to become w)
    bSwap = 1;
    ssd1306_swap(x, y);
    x = WIDTH - x - 1;
    x -= (h - 1);
    break;
  case 2:
    // 180 degree rotation, invert x and y, then shift y around for height.
    x = WIDTH - x - 1;
    y = HEIGHT - y - 1;
    y -= (h - 1);
    break;
  case 3:
    // 270 degree rotation, swap x & y for rotation, then invert y
    bSwap = 1;
    ssd1306_swap(x, y);
    y = HEIGHT - y - 1;
    break;
  }

  if (bSwap)
    SSD1306_drawFastHLineInternal(x, y, h, color);
  else
    SSD1306_drawFastVLineInternal(x, y, h, color);
}

/*!
    @brief  Draw a vertical line with a width and color. Used by public method
   drawFastHLine,drawFastVLine
        @param x
                   Leftmost column -- 0 at left to (screen width - 1) at right.
        @param __y
                   Row of display -- 0 at top to (screen height -1) at bottom.
        @param __h height of the line in pixels
        @param color
                   Line color, one of: SSD1306_BLACK, SSD1306_WHITE or
   SSD1306_INVERSE.
    @return None (void).
    @note   Changes buffer contents only, no immediate effect on display.
            Follow up with a call to display(), or with other graphics
            commands as needed by one's own application.
*/




void SSD1306_drawFastVLineInternal(int16_t x, int16_t __y, int16_t __h, uint16_t color) 
{
  if ((x >= 0) && (x < WIDTH)) { // X coord in bounds?
    if (__y < 0) {               // Clip top
      __h += __y;
      __y = 0;
    }
    if ((__y + __h) > HEIGHT) { // Clip bottom
      __h = (HEIGHT - __y);
    }
    if (__h > 0) { // Proceed only if height is now positive
      // this display doesn't need ints for coordinates,
      // use local byte registers for faster juggling
      uint8_t y = __y, h = __h;
      uint8_t *pBuf = &buffer[(y / 8) * WIDTH + x];

      // do the first partial byte, if necessary - this requires some masking
      uint8_t mod = (y & 7);
      if (mod) {
        // mask off the high n bits we want to set
        mod = 8 - mod;
        // note - lookup table results in a nearly 10% performance
        // improvement in fill* functions
        // uint8_t mask = ~(0xFF >> mod);
        static const uint8_t premask[8] = {0x00, 0x80, 0xC0, 0xE0,
                                           0xF0, 0xF8, 0xFC, 0xFE};
        uint8_t mask = pgm_read_byte(&premask[mod]);
        // adjust the mask if we're not going to reach the end of this byte
        if (h < mod)
          mask &= (0XFF >> (mod - h));

        switch (color) {
        case SSD1306_WHITE:
          *pBuf |= mask;
          break;
        case SSD1306_BLACK:
          *pBuf &= ~mask;
          break;
        case SSD1306_INVERSE:
          *pBuf ^= mask;
          break;
        }
        pBuf += WIDTH;
      }

      if (h >= mod) { // More to go?
        h -= mod;
        // Write solid bytes while we can - effectively 8 rows at a time
        if (h >= 8) {
          if (color == SSD1306_INVERSE) {
            // separate copy of the code so we don't impact performance of
            // black/white write version with an extra comparison per loop
            do {
              *pBuf ^= 0xFF; // Invert byte
              pBuf += WIDTH; // Advance pointer 8 rows
              h -= 8;        // Subtract 8 rows from height
            } while (h >= 8);
          } else {
            // store a local value to work with
            uint8_t val = (color != SSD1306_BLACK) ? 255 : 0;
            do {
              *pBuf = val;   // Set byte
              pBuf += WIDTH; // Advance pointer 8 rows
              h -= 8;        // Subtract 8 rows from height
            } while (h >= 8);
          }
        }

        if (h) { // Do the final partial byte, if necessary
          mod = h & 7;
          // this time we want to mask the low bits of the byte,
          // vs the high bits we did above
          // uint8_t mask = (1 << mod) - 1;
          // note - lookup table results in a nearly 10% performance
          // improvement in fill* functions
          static const uint8_t  postmask[8] = {0x00, 0x01, 0x03, 0x07,
                                                      0x0F, 0x1F, 0x3F, 0x7F};
          uint8_t mask = pgm_read_byte(&postmask[mod]);
          switch (color) {
          case SSD1306_WHITE:
            *pBuf |= mask;
            break;
          case SSD1306_BLACK:
            *pBuf &= ~mask;
            break;
          case SSD1306_INVERSE:
            *pBuf ^= mask;
            break;
          }
        }
      }
    } // endif positive height
  }   // endif x in bounds
}

/*!
    @brief  Return color of a single pixel in display buffer.
    @param  x
            Column of display -- 0 at left to (screen width - 1) at right.
    @param  y
            Row of display -- 0 at top to (screen height -1) at bottom.
    @return true if pixel is set (usually SSD1306_WHITE, unless display invert
   mode is enabled), false if clear (SSD1306_BLACK).
    @note   Reads from buffer contents; may not reflect current contents of
            screen if display() has not been called.
*/



uint8_t SSD1306_getPixel(int16_t x, int16_t y) 
{
  if ((x >= 0) && (x < _width && (y >= 0) && (y < _height))) 
  {
    // Pixel is in-bounds. Rotate coordinates if needed.
    switch (getRotation()) {
    case 1:
      ssd1306_swap(x, y);
      x = WIDTH - x - 1;
      break;
    case 2:
      x = WIDTH - x - 1;
      y = HEIGHT - y - 1;
      break;
    case 3:
      ssd1306_swap(x, y);
      y = HEIGHT - y - 1;
      break;
    }
    return (buffer[x + (y / 8) * WIDTH] & (1 << (y & 7)));
  }
  return 0; // Pixel out of bounds
}

/*!
    @brief  Get base address of display buffer for direct reading or writing.
    @return Pointer to an unsigned 8-bit array, column-major, columns padded
            to full byte boundary if needed.
*/


uint8_t* SSD1306_getBuffer() { return buffer;}




// REFRESH DISPLAY ---------------------------------------------------------

/*!
    @brief  Push data currently in RAM to SSD1306 display.
    @return None (void).
    @note   Drawing operations are not visible until this function is
            called. Call after each graphics command, or after a whole set
            of graphics commands, as best needed by one's own application.
*/


void SSD1306_display() 
{
  //RANSACTION_START
  static const uint8_t dlist1[] = {
      SSD1306_PAGEADDR,
      0,                      // Page start address
      0xFF,                   // Page end (not really, but works here)
      SSD1306_COLUMNADDR, 0}; // Column start address
  ssd1306_commandList(dlist1, sizeof(dlist1));
  ssd1306_command1(WIDTH - 1); // Column end address

  uint16_t count = WIDTH * ((HEIGHT + 7) / 8);
  uint8_t *ptr = buffer;
  Wire.beginTransmission(I2C_adress);
  Wire.SendData((uint8_t)0x40);
  uint16_t bytesOut = 1;
  while (count--) {
  if (bytesOut >= SIZE_BUFFER_I2C_TX) 
  {
      Wire.StopCom();
      Wire.beginTransmission(I2C_adress);
      Wire.SendData((uint8_t)0x40);
      bytesOut = 1;
  }
      Wire.SendData(*ptr++);
      bytesOut++;
    }
    Wire.StopCom();
  
  //TRANSACTION_END
}

// SCROLLING FUNCTIONS -----------------------------------------------------

/*!
    @brief  Activate a right-handed scroll for all or part of the display.
    @param  start
            First row.
    @param  stop
            Last row.
    @return None (void).
*/


// To scroll the whole display, run: display.startscrollright(0x00, 0x0F)
void SSD1306_startscrollright(uint8_t start, uint8_t stop) 
{
  //TRANSACTION_START
  static const uint8_t scrollList1a[] = {
      SSD1306_RIGHT_HORIZONTAL_SCROLL, 0X00};
  ssd1306_commandList(scrollList1a, sizeof(scrollList1a));
  ssd1306_command1(start);
  ssd1306_command1(0X00);
  ssd1306_command1(stop);
  static const uint8_t scrollList1b[] = {0X00, 0XFF,
                                                 SSD1306_ACTIVATE_SCROLL};
  ssd1306_commandList(scrollList1b, sizeof(scrollList1b));
  //TRANSACTION_END
}


/*!
    @brief  Activate a left-handed scroll for all or part of the display.
    @param  start
            First row.
    @param  stop
            Last row.
    @return None (void).
*/

// To scroll the whole display, run: display.startscrollleft(0x00, 0x0F)
void SSD1306_startscrollleft(uint8_t start, uint8_t stop) 
{
  //TRANSACTION_START
  static const uint8_t scrollList2a[] = {SSD1306_LEFT_HORIZONTAL_SCROLL,
                                                 0X00};
  ssd1306_commandList(scrollList2a, sizeof(scrollList2a));
  ssd1306_command1(start);
  ssd1306_command1(0X00);
  ssd1306_command1(stop);
  static const uint8_t scrollList2b[] = {0X00, 0XFF,
                                                 SSD1306_ACTIVATE_SCROLL};
  ssd1306_commandList(scrollList2b, sizeof(scrollList2b));
  //TRANSACTION_END
}

/*!
    @brief  Activate a diagonal scroll for all or part of the display.
    @param  start
            First row.
    @param  stop
            Last row.
    @return None (void).
*/


// display.startscrolldiagright(0x00, 0x0F)
void SSD1306_startscrolldiagright(uint8_t start, uint8_t stop) 
{
  //TRANSACTION_START
  static const uint8_t scrollList3a[] = {
      SSD1306_SET_VERTICAL_SCROLL_AREA, 0X00};
  ssd1306_commandList(scrollList3a, sizeof(scrollList3a));
  ssd1306_command1(HEIGHT);
  static const uint8_t scrollList3b[] = {
      SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL, 0X00};
  ssd1306_commandList(scrollList3b, sizeof(scrollList3b));
  ssd1306_command1(start);
  ssd1306_command1(0X00);
  ssd1306_command1(stop);
  static const uint8_t scrollList3c[] = {0X01, SSD1306_ACTIVATE_SCROLL};
  ssd1306_commandList(scrollList3c, sizeof(scrollList3c));
  //TRANSACTION_END
}

/*!
    @brief  Activate alternate diagonal scroll for all or part of the display.
    @param  start
            First row.
    @param  stop
            Last row.
    @return None (void).
*/


// To scroll the whole display, run: display.startscrolldiagleft(0x00, 0x0F)
void SSD1306_startscrolldiagleft(uint8_t start, uint8_t stop) 
{
  //TRANSACTION_START
  static const uint8_t scrollList4a[] = {
      SSD1306_SET_VERTICAL_SCROLL_AREA, 0X00};
  ssd1306_commandList(scrollList4a, sizeof(scrollList4a));
  ssd1306_command1(HEIGHT);
  static const uint8_t scrollList4b[] = {
      SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL, 0X00};
  ssd1306_commandList(scrollList4b, sizeof(scrollList4b));
  ssd1306_command1(start);
  ssd1306_command1(0X00);
  ssd1306_command1(stop);
  static const uint8_t scrollList4c[] = {0X01, SSD1306_ACTIVATE_SCROLL};
  ssd1306_commandList(scrollList4c, sizeof(scrollList4c));
  //TRANSACTION_END
}

/*!
    @brief  Cease a previously-begun scrolling action.
    @return None (void).
*/

void SSD1306_stopscroll() 
{
  //TRANSACTION_START
  ssd1306_command1(SSD1306_DEACTIVATE_SCROLL);
  //TRANSACTION_END
}

// OTHER HARDWARE SETTINGS -------------------------------------------------

/*!
    @brief  Enable or disable display invert mode (white-on-black vs
            black-on-white).
    @param  i
            If true, switch to invert mode (black-on-white), else normal
            mode (white-on-black).
    @return None (void).
    @note   This has an immediate effect on the display, no need to call the
            display() function -- buffer contents are not changed, rather a
            different pixel mode of the display hardware is used. When
            enabled, drawing SSD1306_BLACK (value 0) pixels will actually draw
   white, SSD1306_WHITE (value 1) will draw black.
*/

void SSD1306_invertDisplay(uint8_t i) 
{
  //TRANSACTION_START
  ssd1306_command1(i ? SSD1306_INVERTDISPLAY : SSD1306_NORMALDISPLAY);
  //TRANSACTION_END
}

void setRotation(uint8_t x)
{
  rotation = (x & 3);
  switch (rotation) 
  {
    case 0:
    case 2:
      _width = WIDTH;
      _height = HEIGHT;
    break;
    case 1:
    case 3:
      _width = HEIGHT;
      _height = WIDTH;
    break;
  }
}

uint8_t getRotation(){ return rotation; }

void testdrawline() 
{
  int16_t i;

  SSD1306_clearDisplay(); // Clear display buffer

  for(i=0; i<_width; i+=4) {
    SSD1306_drawLine(0, 0, i, _height-1, SSD1306_WHITE);
    SSD1306_display(); // Update screen with each newly-drawn line
    CORETIMER_DelayMs(1);
  }
  for(i=0; i<_height; i+=4) {
    SSD1306_drawLine(0, 0, _width-1, i, SSD1306_WHITE);
    SSD1306_display();
    CORETIMER_DelayMs(1);
  }
  CORETIMER_DelayMs(250);

  SSD1306_clearDisplay();

  for(i=0; i<_width; i+=4) {
    SSD1306_drawLine(0, _height-1, i, 0, SSD1306_WHITE);
    SSD1306_display();
    CORETIMER_DelayMs(1);
  }
  for(i=_height-1; i>=0; i-=4) {
    SSD1306_drawLine(0, _height-1, _width-1, i, SSD1306_WHITE);
    SSD1306_display();
    CORETIMER_DelayMs(1);
  }
  CORETIMER_DelayMs(250);

  SSD1306_clearDisplay();

  for(i=_width-1; i>=0; i-=4) {
    SSD1306_drawLine(_width-1, _height-1, i, 0, SSD1306_WHITE);
    SSD1306_display();
    CORETIMER_DelayMs(1);
  }
  for(i=_height-1; i>=0; i-=4) {
    SSD1306_drawLine(_width-1, _height-1, 0, i, SSD1306_WHITE);
    SSD1306_display();
    CORETIMER_DelayMs(1);
  }
  CORETIMER_DelayMs(250);

  SSD1306_clearDisplay();

  for(i=0; i<_height; i+=4) {
    SSD1306_drawLine(_width-1, 0, 0, i, SSD1306_WHITE);
    SSD1306_display();
    CORETIMER_DelayMs(1);
  }
  for(i=0; i<_width; i+=4) {
    SSD1306_drawLine(_width-1, 0, i, _height-1, SSD1306_WHITE);
    SSD1306_display();
    CORETIMER_DelayMs(1);
  }

  CORETIMER_DelayMs(2000); // Pause for 2 seconds
}


void SSD1306_drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color) 
{
  // Update in subclasses if desired!
  if (x0 == x1) {
    if (y0 > y1)
    ssd1306_swap(y0, y1);
    SSD1306_drawFastVLine(x0, y0, y1 - y0 + 1, color);
  } else if (y0 == y1) {
    if (x0 > x1)
    ssd1306_swap(x0, x1);
    SSD1306_drawFastHLine(x0, y0, x1 - x0 + 1, color);
  } else {
    //startWrite();
    SSD1306_writeLine(x0, y0, x1, y1, color);
    //endWrite();
  }
}


void SSD1306_writeLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color) 
{
  int16_t steep = abs(y1 - y0) > abs(x1 - x0);
  if (steep) {
    ssd1306_swap(x0, y0);
    ssd1306_swap(x1, y1);
  }

  if (x0 > x1) {
    ssd1306_swap(x0, x1);
    ssd1306_swap(y0, y1);
  }

  int16_t dx, dy;
  dx = x1 - x0;
  dy = abs(y1 - y0);

  int16_t err = dx / 2;
  int16_t ystep;

  if (y0 < y1) {
    ystep = 1;
  } else {
    ystep = -1;
  }

  for (; x0 <= x1; x0++) {
    if (steep) {
      SSD1306_drawPixel(y0, x0, color);
    } else {
      SSD1306_drawPixel(x0, y0, color);
    }
    err -= dy;
    if (err < 0) {
      y0 += ystep;
      err += dx;
    }
  }
}
/*
void writePixel(int16_t x, int16_t y, uint16_t color)
{
  SSD1306_drawPixel(int16_t x, int16_t y, uint16_t color);
}*/