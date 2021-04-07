#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include "PiWrapper.h"
#include "Arduino.h"

class Temperature: public PiWrapper {
    // Inherits from PiWrapper for interaction with pi
    public:
    int temperature;
    uint8_t pin;

    Temperature(uint8_t pin);

    void getReading();

};

#endif