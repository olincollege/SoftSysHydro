#ifndef PIWRAPPER_H
#define PIWRAPPER_H
#include <Arduino.h>

class PiWrapper {
    public:
    char *port = "/dev/ttyACM0";
    // Send data to the pi
    static char* sendData(int data, char* type);
    // Send data to the pi
    static char* sendData(char* data, char* type);
    // Get data from the pi
    static char* getData(char* request);
};

#endif