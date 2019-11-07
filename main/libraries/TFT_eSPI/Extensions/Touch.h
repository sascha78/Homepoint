 // Coded by Bodmer 10/2/18, see license in root directory.
 // This is part of the TFT_eSPI class and is associated with the Touch Screen handlers

#define ADAFRUIT_FT6206_LIBRARY

#include "Arduino.h"
#include <Wire.h>

#define FT62XX_ADDR           0x38
#define FT62XX_G_FT5201ID     0xA8
#define FT62XX_REG_NUMTOUCHES 0x02

#define FT62XX_NUM_X             0x33
#define FT62XX_NUM_Y             0x34

#define FT62XX_REG_MODE 0x00
#define FT62XX_REG_CALIBRATE 0x02
#define FT62XX_REG_WORKMODE 0x00
#define FT62XX_REG_FACTORYMODE 0x40
#define FT62XX_REG_THRESHHOLD 0x80
#define FT62XX_REG_POINTRATE 0x88
#define FT62XX_REG_FIRMVERS 0xA6
#define FT62XX_REG_CHIPID 0xA3
#define FT62XX_REG_VENDID 0xA8

#define FT62XX_VENDID 0x11
#define FT6206_CHIPID 0x06
#define FT6236_CHIPID 0x36
#define FT6236U_CHIPID 0x64 // mystery!

// calibrated for Adafruit 2.8" ctp screen
#define FT62XX_DEFAULT_THRESHOLD 128

 public:
            // Get the screen touch coordinates, returns true if screen has been touched
           // if the touch cordinates are off screen then x and y are not updated
  uint8_t  getTouch(uint16_t *x, uint16_t *y, uint16_t threshold = 600);
 
  boolean setupFT6206(uint8_t thresh = FT62XX_DEFAULT_THRESHOLD);  
  uint8_t touched(void);

 private:
  
  void writeRegister8(uint8_t reg, uint8_t val);
  uint8_t readRegister8(uint8_t reg);

  void readData(void);
  uint8_t touches;
  uint16_t touchX[2], touchY[2], touchID[2];
