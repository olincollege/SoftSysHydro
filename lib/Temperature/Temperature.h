#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include "PiWrapper.h"
#include "Arduino.h"

class Temperature: public PiWrapper {
    // Inherits from PiWrapper for interaction with pi
    public:
    double resistance;
    double voltage;
    double temperature;
    uint8_t pin;
    char *type = "temp";

    Temperature(uint8_t pin);

    void getRawReading();
    void getTemp();
    void sendSensorLog();

};

#endif