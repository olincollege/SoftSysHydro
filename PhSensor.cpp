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
    sendData(this->ph, "ph_log");
}

void PhSensor::getRange() {
    string response = getData("ph_range");
    // TODO: Parse response and update this->maxPh and this->minPh
}