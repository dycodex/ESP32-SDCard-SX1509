#include "IOHAL.h"

static bool isIOExpanderInitted = false;

IOHAL::IOHAL(IOHAL_MODE mode): mode(mode) {
    IOExpander = new SX1509();
}

IOHAL::~IOHAL() {
    delete IOExpander;
}

void IOHAL::begin() {
    if (mode == IOHAL_SX1509) {
        if (!isIOExpanderInitted) {
            IOExpander->begin(SX1509_ADDRESS);
            isIOExpanderInitted = true;
        }
    }
}

void IOHAL::pinMode(byte pin, byte inOut) {
    if (mode == IOHAL_SX1509) {
        IOExpander->pinMode(pin, inOut);
    } else {
        pinMode(pin, inOut);
    }
}

byte IOHAL::digitalRead(byte pin) {
    if (mode == IOHAL_SX1509) {
        return IOExpander->digitalRead(pin);
    }

    return digitalRead(pin);
}

void IOHAL::digitalWrite(byte pin, byte highLow) {
    if (mode == IOHAL_SX1509) {
        IOExpander->digitalWrite(pin, highLow);
    } else {
        digitalWrite(pin, highLow);
    }
}

SX1509* IOHAL::getSX1509Ptr() {
    return IOExpander;
}
