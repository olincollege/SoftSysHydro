#include "PhUpPump.h"

void PhUpPump::dispense() {
    // TODO:
    // Interface with pump
    // Dispense an amount according to this->interval
    // Update this->lastDispense with current time
};

void PhUpPump::sendLog() {
    sendData(this->lastDispense, "ph_up");
};

void PhUpPump::getInterval() {
    String response = getData("ph_interval");
    // TODO: parse response and update interval data member
};