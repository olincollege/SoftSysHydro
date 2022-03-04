#ifndef PIWRAPPER_H
#define PIWRAPPER_H
#include <Arduino.h>
#include <RTClib.h>

class PiWrapper
{
public:
    String port = "/dev/ttyACM0";
    String systemId = "system/1";
    String sep = ":";
    String query = "";
    typedef struct
    {
        String dataType;
        String reqType;
        String sensorName;
        String data;
    } Query;
    Query q;
    unsigned long timeout = 500;
    // Send a query to the pi
    void sendQuery();
    // Generate the payload to be sent based on q and update query
    void createQuery();
    // Wait for and get response after sending a request
    String getResponse();
    // Determines if timeout has occured
    bool hasTimedOut(uint64_t startTime);
};

#endif