#include "EcPump.h"

EcPump::EcPump(uint8_t analogPin1, uint8_t analogPin2, uint8_t analogPin3) {
    this-> pin1 = analogPin1;
    this-> pin2 = analogPin2;
    this-> pin3 = analogPin3;
}

void EcPump::dispense() {
    // TODO:
    // Interface with pumps
    // Dispense for an amount of time
    ;
}

void EcPump::sendLog() {
    String data = ":ec_up";
    String res = sendData(data, "task");
}

void EcPump::getInterval() {
    String response = getData(this->wrapper->systemId, "dispense_interval");
    if (response != "") {
        int intervalInt = response.toInt();
        this->interval = long(intervalInt);
    }
}

void EcPump::getDispenseTime() {
    String response = getData(this->wrapper->systemId, "ec_dispense_time");
    if (response != "") {
        int dispTime = response.toInt();
        this->dispenseTime = long(dispTime);
    }
}