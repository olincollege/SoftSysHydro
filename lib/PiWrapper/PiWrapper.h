#ifndef PIWRAPPER_H
#define PIWRAPPER_H
#include <Arduino.h>


class PiWrapper {
    public:
    String port = "/dev/ttyACM0";
    String systemId = "system/1";
    // Send data to the pi
    static String sendData(double data, String type);
    // Send data to the pi
    static String sendData(String data, String type);
    // Get data from the pi
    static String getData(String request, String type);
};

#endif