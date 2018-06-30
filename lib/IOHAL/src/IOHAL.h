#ifndef GPIO_SX_NATIVE_HAL_H
#define GPIO_SX_NATIVE_HAL_H

#define SX1509_ADDRESS 0x3E

#include <Arduino.h>
#include <SparkFunSX1509.h>

typedef enum IOHAL_MODE {
    IOHAL_NATIVE,
    IOHAL_SX1509
} IOHAL_MODE;

class IOHAL {
public:
    IOHAL(IOHAL_MODE mode = IOHAL_NATIVE);
    ~IOHAL();

    void begin();
    void pinMode(byte pin, byte inOut);
    void digitalWrite(byte pin, byte highLow);
    byte digitalRead(byte pin);
    SX1509* getSX1509Ptr();

private:
    IOHAL_MODE mode;
    SX1509* IOExpander;
};

#endif
