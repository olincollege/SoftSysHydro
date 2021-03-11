#include "PiWrapper.h"

class PhSensor: public PiWrapper {
    // Inherits from PiWrapper for interacting with pi
    public:
    int ph;
    int maxPh;
    int minPh;
    int interval;

    // Constructor
    PhSensor(); 
    // Get pH readings from sensor
    // Updates: ph data member
    void getReading();
    // Check if ph reading is above range
    bool aboveRange();
    // Check if ph reading below range
    bool belowRange();
    // Send latest sensor reading to pi via wrapper
    void sendSensorLog();
    // Gets pH range from pi via wrapper
    // Updates: maxPh and minPh data members
    void getRange();
    // Get dispense interval from pi via wrapper
    // Updates: interval data member
    void getInterval();
};