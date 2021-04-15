#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include "PiWrapper.h"
#include "Arduino.h"

class Temperature: public PiWrapper {
    // Inherits from PiWrapper for interaction with pi
    public:
    PiWrapper* wrapper = new PiWrapper();
    double resistance;
    double voltage;
    double temperature;
    int interval = 1200;
    long lastReading;
    uint8_t pin;
    String type = "temp";

    Temperature(uint8_t pin);

    void getRawReading();
    void getTemp();
    void sendSensorLog();
    void getInterval();

};

#endif