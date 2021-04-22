#include "WaterLevel.h"
#include "Arduino.h"

WaterLevel::WaterLevel(uint8_t pin) {
    this -> pin = pin;
}

void WaterLevel::getRawReading() {
    this -> reading = analogRead(this -> pin);
}

void WaterLevel::getStatus() {
    getRawReading();
    if (this -> reading > this -> lowCutoff) 
    {
        this -> status = "Low";
    }
    else if (this -> reading > this -> mediumCutoff)
    {
        this -> status = "Medium";
    }
    else 
    {
        this -> status = "High";
    }
}

void WaterLevel::sendSensorLog() {
    getStatus();
    String res = sendData(this->status, this->type);
}

void WaterLevel::getInterval() {
    String response = getData(this->wrapper->systemId, "sensor_interval");
    if (response != "") {
        this->interval = response.toInt();
    }
}