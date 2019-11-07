// Change the width and height if required (defined in portrait mode)
// or use the constructor to over-ride defaults
#define TFT_WIDTH  240
#define TFT_HEIGHT 320


// Color definitions for backwards compatibility with old sketches
// use colour definitions like TFT_BLACK to make sketches more portable
#define ILI9342_BLACK       0x0000      /*   0,   0,   0 */
#define ILI9342_NAVY        0x000F      /*   0,   0, 128 */
#define ILI9342_DARKGREEN   0x03E0      /*   0, 128,   0 */
#define ILI9342_DARKCYAN    0x03EF      /*   0, 128, 128 */
#define ILI9342_MAROON      0x7800      /* 128,   0,   0 */
#define ILI9342_PURPLE      0x780F      /* 128,   0, 128 */
#define ILI9342_OLIVE       0x7BE0      /* 128, 128,   0 */
#define ILI9342_LIGHTGREY   0xC618      /* 192, 192, 192 */
#define ILI9342_DARKGREY    0x7BEF      /* 128, 128, 128 */
#define ILI9342_BLUE        0x001F      /*   0,   0, 255 */
#define ILI9342_GREEN       0x07E0      /*   0, 255,   0 */
#define ILI9342_CYAN        0x07FF      /*   0, 255, 255 */
#define ILI9342_RED         0xF800      /* 255,   0,   0 */
#define ILI9342_MAGENTA     0xF81F      /* 255,   0, 255 */
#define ILI9342_YELLOW      0xFFE0      /* 255, 255,   0 */
#define ILI9342_WHITE       0xFFFF      /* 255, 255, 255 */
#define ILI9342_ORANGE      0xFD20      /* 255, 165,   0 */
#define ILI9342_GREENYELLOW 0xAFE5      /* 173, 255,  47 */
#define ILI9342_PINK        0xF81F


// Delay between some initialisation commands
#define TFT_INIT_DELAY 0x80 // Not used unless commandlist invoked


// Generic commands used by TFT_eSPI.cpp
#define TFT_NOP     0x00
#define TFT_SWRST   0x01

#define TFT_CASET   0x2A
#define TFT_PASET   0x2B
#define TFT_RAMWR   0x2C

#define TFT_RAMRD   0x2E
#define TFT_IDXRD   0xDD // ILI9342 only, indexed control register read

#define TFT_MADCTL  0x36
#define TFT_MAD_MY  0x80
#define TFT_MAD_MX  0x40
#define TFT_MAD_MV  0x20
#define TFT_MAD_ML  0x10
#define TFT_MAD_BGR 0x08
#define TFT_MAD_MH  0x04
#define TFT_MAD_RGB 0x00

#define TFT_INVOFF  0x20
#define TFT_INVON   0x21


// All ILI9342 specific commands some are used by init()
#define ILI9342_NOP     0x00
#define ILI9342_SWRESET 0x01
#define ILI9342_RDDID   0x04
#define ILI9342_RDDST   0x09

#define ILI9342_SLPIN   0x10
#define ILI9342_SLPOUT  0x11
#define ILI9342_PTLON   0x12
#define ILI9342_NORON   0x13

#define ILI9342_RDMODE  0x0A
#define ILI9342_RDMADCTL  0x0B
#define ILI9342_RDPIXFMT  0x0C
#define ILI9342_RDIMGFMT  0x0D
#define ILI9342_RDSELFDIAG  0x0F

#define ILI9342_INVOFF  0x20
#define ILI9342_INVON   0x21
#define ILI9342_GAMMASET 0x26
#define ILI9342_DISPOFF 0x28
#define ILI9342_DISPON  0x29

#define ILI9342_CASET   0x2A
#define ILI9342_PASET   0x2B
#define ILI9342_RAMWR   0x2C
#define ILI9342_RAMRD   0x2E

#define ILI9342_PTLAR   0x30
#define ILI9342_VSCRDEF 0x33
#define ILI9342_MADCTL  0x36
#define ILI9342_VSCRSADD 0x37
#define ILI9342_PIXFMT  0x3A

#define ILI9342_WRDISBV  0x51
#define ILI9342_RDDISBV  0x52
#define ILI9342_WRCTRLD  0x53

#define ILI9342_FRMCTR1 0xB1
#define ILI9342_FRMCTR2 0xB2
#define ILI9342_FRMCTR3 0xB3
#define ILI9342_INVCTR  0xB4
#define ILI9342_DFUNCTR 0xB6

#define ILI9342_PWCTR1  0xC0
#define ILI9342_PWCTR2  0xC1
#define ILI9342_PWCTR3  0xC2
#define ILI9342_PWCTR4  0xC3
#define ILI9342_PWCTR5  0xC4
#define ILI9342_VMCTR1  0xC5
#define ILI9342_VMCTR2  0xB7

#define ILI9342_RDID4   0xDD
//#define ILI9342_RDINDEX 0xD9
#define ILI9342_RDID1   0xDA
#define ILI9342_RDID2   0xDB
#define ILI9342_RDID3   0xDC
//#define ILI9342_RDIDX   0xDD // TBC

#define ILI9342_GMCTRP1 0xE0
#define ILI9342_GMCTRN1 0xE1

#define ILI9342_MADCTL_MY  0x80
#define ILI9342_MADCTL_MX  0x40
#define ILI9342_MADCTL_MV  0x20
#define ILI9342_MADCTL_ML  0x10
#define ILI9342_MADCTL_RGB 0x00
#define ILI9342_MADCTL_BGR 0x08
#define ILI9342_MADCTL_MH  0x04
