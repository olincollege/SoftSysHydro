#include "PhSensor.h"
#include "ph_grav.h"

PhSensor::PhSensor(uint8_t analogPin)
{
    pin = analogPin;
}

void PhSensor::getReading()
{
    Gravity_pH pH = pin; // Assigns pin for pH signal
    ph = pH.read_ph();
}

bool PhSensor::isAboveRange()
{
    if (ph > maxPh)
    {
        return true;
    }
    else
    {
        return false;
    };
}

void PhSensor::sendSensorLog()
{
    createQuery("post", ph, type);
    sendQuery();
}

void PhSensor::getMaxPh()
{
    createQuery("get", systemId, "ph_high");
    sendQuery();
    String response = getResponse();
    if (response != "")
    {
        maxPh = response.toDouble();
    }
}

void PhSensor::getInterval()
{
    createQuery("get", systemId, "sensor_interval");
    sendQuery();
    String response = getResponse();
    if (response != "")
    {
        interval = response.toInt();
    }
}