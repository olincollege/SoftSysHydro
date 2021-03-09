#include "PiWrapper.h"

class PhSensor: public PiWrapper {
    // Inherits from PiWrapper for sending information to pi
    public:
    int ph;
    int max_ph;
    int min_ph;

    // Constructor
    PhSensor(); 
    // Get pH readings from sensor
    void getReading();
    // Check if ph reading is in range
    static bool inRange(int min, int max);
    // Send data to pi via wrapper
    void sendToPi();
    // Get pH range from pi via wrapper
    void getRangeFromPi();
};