#include "ECSensor.h"
#include "Arduino.h"

ECSensor::ECSensor() {

}

void ECSensor::getReading() {
    this -> reading.reserve(30);
    this -> reading = Serial3.readStringUntil(13);
}

void ECSensor::sendSensorLog() {
    getReading();
    String res = sendData(this -> reading, this -> type);
}