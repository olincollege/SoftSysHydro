#ifndef PIWRAPPER_H
#define PIWRAPPER_H
#include <Arduino.h>

class PiWrapper {
    public:
    String port = "/dev/ttyACM0";
    // Send data to the pi
    static String sendData(int data, String type);
    // Send data to the pi
    static void sendData(String data, String type);
    // Get data from the pi
    static String getData(String request);
};

#endif