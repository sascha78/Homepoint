// The following touch screen support code by maxpautsch was merged 1/10/17
// https://github.com/maxpautsch

// Define TOUCH_CS is the user setup file to enable this code

// A demo is provided in examples Generic folder

// Additions by Bodmer to double sample, use Z value to improve detection reliability
// and to correct rotation handling

// See license in root directory.

#define FT6206_DEBUG
//#define I2C_DEBUG

/***************************************************************************************
** Function name:           getTouch
** Description:             read callibrated position. Return false if not pressed. 
***************************************************************************************/
#define Z_THRESHOLD 150 // Touch pressure threshold for validating touches
uint8_t TFT_eSPI::getTouch(uint16_t *x, uint16_t *y, uint16_t threshold){
  uint16_t x_tmp, y_tmp;

  readData();
  if (touches == 0) {
    *x = 0;
    *y = 0;
    return false;
  } else {
    *x = 320 - touchX[0];
    *y = 240 - touchY[0];
    return 10;
  }
}

/**************************************************************************/
/*! 
    @brief  Setups the I2C interface and hardware, identifies if chip is found
    @param  thresh Optional threshhold-for-touch value, default is FT6206_DEFAULT_THRESSHOLD but you can try changing it if your screen is too/not sensitive.
    @returns True if an FT6206 is found, false on any failure
*/
/**************************************************************************/
boolean TFT_eSPI::setupFT6206(uint8_t thresh) {
  Wire.begin();

#ifdef FT6206_DEBUG
  Serial.print("Vend ID: 0x"); 
  Serial.println(readRegister8(FT62XX_REG_VENDID), HEX);
  Serial.print("Chip ID: 0x"); 
  Serial.println(readRegister8(FT62XX_REG_CHIPID), HEX);
  Serial.print("Firm V: "); Serial.println(readRegister8(FT62XX_REG_FIRMVERS));
  Serial.print("Point Rate Hz: "); 
  Serial.println(readRegister8(FT62XX_REG_POINTRATE));
  Serial.print("Thresh: "); 
  Serial.println(readRegister8(FT62XX_REG_THRESHHOLD));

  // dump all registers
  for (int16_t i=0; i<0x10; i++) {
    Serial.print("I2C $"); Serial.print(i, HEX);
    Serial.print(" = 0x"); Serial.println(readRegister8(i), HEX);
  }
#endif

  // change threshhold to be higher/lower
  writeRegister8(FT62XX_REG_THRESHHOLD, thresh);
  
  if (readRegister8(FT62XX_REG_VENDID) != FT62XX_VENDID) {
    return false;
  }
  uint8_t id = readRegister8(FT62XX_REG_CHIPID);
  if ((id != FT6206_CHIPID) && (id != FT6236_CHIPID) && (id != FT6236U_CHIPID)) {
    return false;
  }

  return true;
}

/**************************************************************************/
/*! 
    @brief  Determines if there are any touches detected
    @returns Number of touches detected, can be 0, 1 or 2
*/
/**************************************************************************/
uint8_t TFT_eSPI::touched(void) {
  uint8_t n = readRegister8(FT62XX_REG_NUMTOUCHES);
  if (n > 2) {
    n = 0;
  }
  return n;
}

/************ lower level i/o **************/

/**************************************************************************/
/*! 
    @brief  Reads the bulk of data from captouch chip. Fill in {@link touches}, {@link touchX}, {@link touchY} and {@link touchID} with results
*/
/**************************************************************************/
void TFT_eSPI::readData(void) {

  uint8_t i2cdat[16];
  Wire.beginTransmission(FT62XX_ADDR);
  Wire.write((byte)0);  
  Wire.endTransmission();

  Wire.requestFrom((byte)FT62XX_ADDR, (byte)16);
  for (uint8_t i=0; i<16; i++)
    i2cdat[i] = Wire.read();

#ifdef FT6206_DEBUG
  for (int16_t i=0; i<16; i++) {
    Serial.print("I2C $"); Serial.print(i, HEX); 
    Serial.print(" = 0x"); Serial.println(i2cdat[i], HEX);
  }
#endif

  touches = i2cdat[0x02];
  if ((touches > 2) || (touches == 0)) {
    touches = 0;
  }

#ifdef FT6206_DEBUG
  Serial.print("# Touches: "); Serial.println(touches);

  for (uint8_t i=0; i<16; i++) {
    Serial.print("0x"); Serial.print(i2cdat[i], HEX); Serial.print(" ");
  }
  Serial.println();
  if (i2cdat[0x01] != 0x00) {
    Serial.print("Gesture #"); 
    Serial.println(i2cdat[0x01]);
  }
#endif

  for (uint8_t i=0; i<2; i++) {
    touchX[i] = i2cdat[0x03 + i*6] & 0x0F;
    touchX[i] <<= 8;
    touchX[i] |= i2cdat[0x04 + i*6]; 
    touchY[i] = i2cdat[0x05 + i*6] & 0x0F;
    touchY[i] <<= 8;
    touchY[i] |= i2cdat[0x06 + i*6];
    touchID[i] = i2cdat[0x05 + i*6] >> 4;
  }

#ifdef FT6206_DEBUG
  Serial.println();
  for (uint8_t i=0; i<touches; i++) {
    Serial.print("ID #"); Serial.print(touchID[i]); 
    Serial.print("\t("); Serial.print(touchX[i]);
    Serial.print(", "); Serial.print(touchY[i]);
    Serial.print (") ");
  }
  Serial.println();
#endif
}

uint8_t TFT_eSPI::readRegister8(uint8_t reg) {
  uint8_t x ;
  // use i2c
  Wire.beginTransmission(FT62XX_ADDR);
  Wire.write((byte)reg);
  Wire.endTransmission();
  
  Wire.requestFrom((byte)FT62XX_ADDR, (byte)1);
  x = Wire.read();

#ifdef I2C_DEBUG
  Serial.print("$"); Serial.print(reg, HEX); 
  Serial.print(": 0x"); Serial.println(x, HEX);
#endif

  return x;
}

void TFT_eSPI::writeRegister8(uint8_t reg, uint8_t val) {
  // use i2c
  Wire.beginTransmission(FT62XX_ADDR);
  Wire.write((byte)reg);
  Wire.write((byte)val);
  Wire.endTransmission();
}
