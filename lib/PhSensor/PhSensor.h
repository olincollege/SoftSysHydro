#ifndef PHSENSOR_H
#define PHSENSOR_H
#include "PiWrapper.h"

class PhSensor: public PiWrapper {
    // Inherits from PiWrapper for interacting with pi
    public:
    PiWrapper* wrapper = new PiWrapper();
    String type = "ph";
    long lastReading;
    double ph;
    double maxPh = 7;
    int interval = 120;
    uint8_t pin;

    // Constructor
    PhSensor(uint8_t analogPin);
    // Get pH readings from sensor
    // Updates: ph data member
    void getReading();
    // Check if ph reading is above range
    bool aboveRange();
    // Send latest sensor reading to pi via wrapper
    void sendSensorLog();
    // Gets max pH from pi via wrapper
    // Updates: maxPh data member
    void getMaxPh();
    // Get dispense interval from pi via wrapper
    // Updates: interval data member
    void getInterval();
};

#endif