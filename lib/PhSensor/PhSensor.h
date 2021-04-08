#ifndef PHSENSOR_H
#define PHSENSOR_H
#include "PiWrapper.h"

class PhSensor: public PiWrapper {
    // Inherits from PiWrapper for interacting with pi
    public:
    char *type = "ph";
    int ph;
    int maxPh = 7.5;
    int minPh = 5.5;
    int interval;
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
    // Gets pH range from pi via wrapper
    // Updates: maxPh and minPh data members
    void getRange();
    // Get dispense interval from pi via wrapper
    // Updates: interval data member
    void getInterval();
};

#endif