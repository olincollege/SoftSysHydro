#ifndef ECPUMP_H
#define ECPUMP_H
#include "PiWrapper.h"

class EcPump: public PiWrapper {
    // Inherits from PiWrapper for interacting with pi
    public:
    PiWrapper* wrapper = new PiWrapper();
    long lastDispense;
    long interval = 1200;
    long dispenseTime = 10;
    String type = "ec_up";
    uint8_t pin1;
    uint8_t pin2;
    uint8_t pin3;

    // Constructor
    EcPump(uint8_t analogPin1, uint8_t analogPin2, uint8_t analogPin3);
    // Dispense nutrients for a set amount of time
    // Updates lastDispense data member
    void dispense();
    // Send log of action to pi via pi wrapper
    void sendLog();
    // Get dispense interval from pi via pi wrapper
    void getInterval();
    // Get the length of time to run pumps
    void getDispenseTime();
};

#endif