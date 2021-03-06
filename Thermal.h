#ifndef Thermal_h
#define Thermal_h

#if ARDUINO >= 100
 #include "Arduino.h"
 #include "SoftwareSerial.h"
#else
 #include "WProgram.h"
 #include "WConstants.h"
 #include "NewSoftSerial.h"
#endif

#define UPC_A 0
#define UPC_E 1 
#define EAN13 2
#define EAN8  3 
#define CODE39 4
#define I25   5 
#define CODEBAR 6 
#define CODE93 7 
#define CODE128 8 
#define CODE11  9
#define MSI 10


class Thermal : public Print {
  public:

    Thermal(int RX_Pin, int TX_Pin);  // constructor
    void begin();
    void setDefault();
    void test();
#if ARDUINO >= 100
    size_t write(uint8_t c);
#else
    void write(uint8_t c);
#endif

    void inverseOn();
    void inverseOff();
    void doubleHeightOn();
    void doubleHeightOff();
    void boldOn();
    void boldOff();
    void underlineOn();
    void underlineOff();
    
    void justify(char value);
    void feed(uint8_t x = 1);
    void sleep();
    void wake();

    void setCharSpacing(int spacing);
    void setSize(char value);
    void setLineHeight(int val = 32);

    void printBarcode(char * text, uint8_t type);
    void setBarcodeHeight(int val);

    void printBitmap(uint8_t w, uint8_t h,  const uint8_t *bitmap);

    // ??
    void tab();
    
 private:
#if ARDUINO >= 100
    SoftwareSerial * _printer;
#else
    NewSoftSerial * _printer;
#endif
    boolean linefeedneeded;
    

    // little helpers to make code easier to read&use
    void writeBytes(uint8_t a, uint8_t b);
    void writeBytes(uint8_t a, uint8_t b, uint8_t c);
    void writeBytes(uint8_t a, uint8_t b, uint8_t c, uint8_t d);

    int _RX_Pin;
    int _TX_Pin;
    
    int heatTime;
    int heatInterval;
    char printDensity;
    char printBreakTime;
};

#endif
