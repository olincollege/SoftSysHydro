#include "ECSensor.h"
#include "Arduino.h"

ECSensor::ECSensor() {
    ;
}

void ECSensor::getReading() {
    this -> reading.reserve(30);
    this -> reading = Serial3.readStringUntil(13);
}

void ECSensor::sendSensorLog() {
    getReading();
    String res = sendData(this -> reading, this -> type);
}

void ECSensor::getMinEC() {
    String response = getData(this->wrapper->systemId, "ec_low");
    if (response != "") {
        this->minEC = response.toDouble();
    }
}

void ECSensor::getInterval() {
    String response = getData(this->wrapper->systemId, "sensor_interval");
    if (response != "") {
        this->interval = response.toInt();
    }
}