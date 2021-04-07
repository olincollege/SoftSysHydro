#include "Temperature.h"
#include "Arduino.h"

Temperature::Temperature(uint8_t pin) {
    this->pin = pin;
}

int Temperature::getRawReading() {
    int voltage;
    voltage = analogRead(this->pin);
    return voltage;
}

double Temperature::getTemp() {
    double temperature;
    int v_out = getRawReading();
    int resistance = 10000 * v_out / (5 - v_out);
    temperature = (double) (267.4 * pow(resistance,-0.1112) - 182);
}