#include "PhPump.h"

void PhPump::dispense() {
    // TODO:
    // Interface with pump
    // Dispense an amount according to this->interval
    // Update this->lastDispense with current time
};

void PhPump::sendLog() {
    char *res = sendData(this->lastDispense, this->type);
    // TODO: Handle error
};

void PhPump::getInterval() {
    String response = getData(this->interval_req);
    // TODO: parse response and update interval data member
};