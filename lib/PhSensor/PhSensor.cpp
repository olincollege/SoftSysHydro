#include "PhSensor.h"
#include "ph_grav.h"

PhSensor::PhSensor(uint8_t analogPin) {
    pin = analogPin;
}

void PhSensor::getReading() {
    Gravity_pH pH = pin; //Assigns pin for pH signal
    ph = pH.read_ph();
}

bool PhSensor::isAboveRange() {
    if (ph > maxPh) {
        return true;
    } else {
        return false;
    };
}

void PhSensor::sendSensorLog() {
    query = createQuery("post", ph, type);
    sendQuery(query);
}

void PhSensor::getMaxPh() {
    query = createQuery("get", systemId, "ph_high");
    String response = getResponse();
    if (response != "") {
        maxPh = response.toDouble();
    }
}

void PhSensor::getInterval() {
    query = createQuery("get", systemId, "sensor_interval");
    String response = getResponse();
    if (response != "") {
        int intervalInt = response.toInt();
        interval = long(intervalInt);
    }
}