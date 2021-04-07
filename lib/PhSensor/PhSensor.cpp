#include "PhSensor.h"
#include <ph_grav.h>

PhSensor::PhSensor(uint8_t analogPin) {
    this-> pin = A0;
}

void PhSensor::getReading() {
    Gravity_pH pH = this->pin; //Assigns pin for pH signal
    this -> ph = pH.read_ph();
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
    char *res = sendData(this->ph, this->type);
    // TODO: Handle if res == "error"
}

void PhSensor::getRange() {
    char *data = "/range";
    char *response = getData(strcat(this->type, data));
    // TODO: Parse response and update this->maxPh and this->minPh
}