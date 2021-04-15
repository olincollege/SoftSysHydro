#ifndef PHPUMP_H
#define PHPUMP_H
#include "PiWrapper.h"

class PhPump: public PiWrapper {
    // Inherits from PiWrapper for interacting with pi
    public:
    PiWrapper* wrapper = new PiWrapper();
    long lastDispense;
    int interval = 1200;
    String type = "ph_down";
    uint8_t pin;

    // Constructor
    PhPump(uint8_t analogPin);
    // Dispense pH up solution for a set amount of time
    // Updates lastDispense data member
    void dispense();
    // Send log of action to pi via pi wrapper
    void sendLog();
    // Get dispense interval from pi via pi wrapper
    void getInterval();
};

#endif