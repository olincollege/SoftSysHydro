#ifndef PHUPPUMP_H
#define PHUPPUMP_H
#include "PiWrapper.h"

class PhUpPump: public PiWrapper {
    // Inherits from PiWrapper for interacting with pi
    public:
    String lastDispense;
    int interval;

    // Dispense pH up solution for a set amount of time
    // Updates lastDispense data member
    void dispense();
    // Send log of action to pi via pi wrapper
    void sendLog();
    // Get dispense interval from pi via pi wrapper
    void getInterval();
};

#endif