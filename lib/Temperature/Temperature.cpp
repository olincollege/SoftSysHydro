#include "Temperature.h"
#include "Arduino.h"

Temperature::Temperature(uint8_t pin) {
    this -> pin = pin;
}

void Temperature::getRawReading() {
    this -> voltage = analogRead(this -> pin) * 5.00 / 1024;

}

void Temperature::getTemp() {
    getRawReading();
    this->resistance = (double) 10 * this->voltage / (5 - voltage);
    this->temperature = (double) (267.4 * pow(resistance,-0.1112) - 182);
}

void Temperature::sendSensorLog() {
    getTemp();
    char *res = sendData(this->temperature, this->type);
}