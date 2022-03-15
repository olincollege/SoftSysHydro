#ifndef PIWRAPPER_H
#define PIWRAPPER_H
#include <Arduino.h>
#include <RTClib.h>

class PiWrapper
{
public:
    String sep = ":";
    String query = "";
    typedef struct
    {
        String dataType;
        String reqType;
        String sensorName;
        String data;
    } Query;
    uint64_t timeout = 20000;
    // Send a query to the pi
    void sendQuery();
    // Create the payload to be sent based on q and update query
    void createQuery(Query q);
    // Wait for and get response after sending a request
    String getResponse();
    // Determines if timeout has occured
    bool hasTimedOut(uint64_t startTime);
};

#endif