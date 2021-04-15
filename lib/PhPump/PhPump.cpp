#include "PhPump.h"

PhPump::PhPump(uint8_t analogPin) {
    this-> pin = analogPin;
}

void PhPump::dispense() {
    // TODO:
    // Interface with pump
    // Dispense an amount according to this->interval
    // Update this->lastDispense with current time
};

void PhPump::sendLog() {
    String res = sendData(this->lastDispense, this->type);
    // TODO: Handle error
};

void PhPump::getInterval() {
    String response = getData(this->wrapper->systemId, "check_ec_ph_interval");
    if (response != "") {
        this->interval = response.toInt();
    }
};