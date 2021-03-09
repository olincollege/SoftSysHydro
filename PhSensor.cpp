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

static bool inRange(int min, int max, int ph) {
    // Boolean return if the ph reading is in desired range
    if (ph < max && ph > min) {
        return true;
    } else {
        return false;
    };
}

void PhSensor::sendToPi() {
    // TODO: implement
    // sends data to pi
    ;
}

void PhSensor::getRangeFromPi() {
    // TODO: implement
    // gets the max and min ph from pi
    ;
}