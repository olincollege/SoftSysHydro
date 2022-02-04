#include "PhPump.h"

PhPump::PhPump(uint8_t analogPin) {
    this-> pin = analogPin;
}

void PhPump::dispense() {
    // TODO:
    // Interface with pump
    // Dispense an amount
    ;
}

void PhPump::sendLog() {
    String data = ":ph_down";
    String res = sendData(data, "task");
    // TODO: Handle error
}

void PhPump::getInterval() {
    String response = getData(this->wrapper->systemId, "dispense_interval");
    if (response != "") {
        int intervalInt = response.toInt();
        this->interval = long(intervalInt);
    }
}

void PhPump::getDispenseTime() {
    String response = getData(this->wrapper->systemId, "ph_dispense_time");
    if (response != "") {
        int dispTime = response.toInt();
        this->dispenseTime = long(dispTime);
    }
}