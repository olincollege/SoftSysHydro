#include "PhPump.h"

PhPump::PhPump(uint8_t analogPin) {
    this-> pin = analogPin;
}

void PhPump::dispense() {
    // TODO:
    // Interface with pump
    // Dispense an amount
};

void PhPump::sendLog() {
    String data = this->lastDispense + ": ph_down";
    String res = sendData(data, "task");
    // TODO: Handle error
};

void PhPump::getInterval() {
    String response = getData(this->wrapper->systemId, "dispense_interval");
    if (response != "") {
        this->interval = response.toInt();
    }
};