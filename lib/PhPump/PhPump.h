#ifndef PHPUMP_H
#define PHPUMP_H
#include "PiWrapper.h"

class PhPump: public PiWrapper {
    // Inherits from PiWrapper for interacting with pi
    public:
    char* lastDispense;
    int interval;
    char *type = "ph_down";
    char *interval_req = "ph/interval";

    // Dispense pH up solution for a set amount of time
    // Updates lastDispense data member
    void dispense();
    // Send log of action to pi via pi wrapper
    void sendLog();
    // Get dispense interval from pi via pi wrapper
    void getInterval();
};

#endif