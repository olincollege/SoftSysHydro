#ifndef PIWRAPPER_H
#define PIWRAPPER_H
#include <Arduino.h>


class PiWrapper {
    public:
    String port = "/dev/ttyACM0";
    String systemId = "system/1";
    HardwareSerial serial = Serial;
    unsigned long timeout = 5000;
    // Send a query to the pi
    void sendQuery(String query);
    // Generate the payload to be sent
    String createQuery(String reqType, String data, String type);
    // Generate the payload to be sent
    String createQuery(String reqType, double data, String type);
    // Wait for and get response after sending a request
    String getResponse();
    // Determines if timeout has occured
    bool hasTimedOut(unsigned long startTime);
};

#endif