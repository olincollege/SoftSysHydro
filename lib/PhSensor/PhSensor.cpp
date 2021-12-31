#include "PhSensor.h"
#include <ph_grav.h>

PhSensor::PhSensor(uint8_t analogPin) {
    this-> pin = analogPin;
}

void PhSensor::getReading() {
    Gravity_pH pH = this->pin; //Assigns pin for pH signal
    this -> ph = pH.read_ph();
}

bool PhSensor::aboveRange() {
    getReading();
    if (this->ph > this->maxPh) {
        return true;
    } else {
        return false;
    };
}

void PhSensor::sendSensorLog() {
    getReading();
    String res = sendData(this->ph, this->type);
}

void PhSensor::getMaxPh() {
    String response = getData(this->wrapper->systemId, "ph_high");
    if (response != "") {
        this->maxPh = response.toDouble();
    }
}

void PhSensor::getInterval() {
    String response = getData(this->wrapper->systemId, "sensor_interval");
    if (response != "") {
        int intervalInt = response.toInt();
        this->interval = long(intervalInt);
    }
}