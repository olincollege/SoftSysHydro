#ifndef ECSENSOR_H
#define ECSENSOR_H
#include "PiWrapper.h"

class ECSensor: public PiWrapper {
    public:
    PiWrapper* wrapper = new PiWrapper();
    String type = "ec";
    String reading;
    
    ECSensor();
    void getReading();
    void sendSensorLog();
};

#endif