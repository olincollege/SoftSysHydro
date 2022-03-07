#include "PhSensor.h"

PhSensor::PhSensor(uint8_t analogPin)
{
    pin = analogPin;
}

void PhSensor::getReading()
{
    Gravity_pH pH = pin;
    ph = pH.read_ph();
}

bool PhSensor::isAboveRange()
{
    return ph > maxPh;
}

void PhSensor::sendSensorLog()
{
    q = {
        "sensor",
        "post",
        "ph",
        (String)ph};
    sendQuery();
    String response = getResponse();
}

void PhSensor::getMaxPh()
{
    q = {
        "system",
        "get",
        "phMax",
        "1"};
    sendQuery();
    String response = getResponse();
    if (response != "")
    {
        maxPh = response.toFloat();
    }
}

void PhSensor::getInterval()
{
    q = {
        "system",
        "get",
        "phSenseInterval",
        "1"};
    sendQuery();
    String response = getResponse();
    if (response != "")
    {
        interval = response.toInt();
    }
}