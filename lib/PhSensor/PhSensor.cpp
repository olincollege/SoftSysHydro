#include "PhSensor.h"

PhSensor::PhSensor() {
    ;
}

void PhSensor::getReading() {
    // TODO:
    // Interface with ph sensor
    // Get the reading
    // Update ph data member
    ;
}

bool PhSensor::aboveRange() {
    if (this->ph > this->maxPh) {
        return true;
    } else {
        return false;
    };
}

bool PhSensor::belowRange() {
    if (this->ph < this->minPh) {
        return true;
    } else {
        return false;
    };
}

void PhSensor::sendSensorLog() {
    String res = sendData(this->ph, "ph_log");
    // TODO: Handle if res == "error"
}

void PhSensor::getRange() {
    String response = getData("ph_range");
    // TODO: Parse response and update this->maxPh and this->minPh
}