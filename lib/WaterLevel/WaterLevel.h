#ifndef WATERLEVEL_H
#define WATERLEVEL_H
#include "PiWrapper.h"
#include "Arduino.h"

class WaterLevel: public PiWrapper {
    // Inherits from PiWrapper for interaction with pi
    public:
    PiWrapper* wrapper = new PiWrapper();
    int reading; 
    int interval = 120;
    long lastReading;
    uint8_t pin;
    String status = "";
    String type = "water";

    // Based on resistors on breadboard
    int lowCutoff = 1000;
    int mediumCutoff = 900;

    WaterLevel(uint8_t pin);

    void getRawReading();
    void getStatus();
    void sendSensorLog();
    void getInterval();
};


#endif