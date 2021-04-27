#ifndef ECSENSOR_H
#define ECSENSOR_H
#include "PiWrapper.h"

class ECSensor: public PiWrapper {
    public:
    PiWrapper* wrapper = new PiWrapper();
    String type = "ec";
    String reading;
    long lastReading;
    long interval = 120;
    double minEC = 1.5; // TODO: update this to a reasonable value

    
    ECSensor();
    void getReading();
    void sendSensorLog();
    void getInterval();
    void getMinEC();
};

#endif