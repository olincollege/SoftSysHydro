#include "PiWrapper.h"

String PiWrapper::sendData(int data, String type) {
    String response = "waiting";
    Serial.print(type);
    Serial.print(data);
    Serial.print("\n");
    while (response == "waiting"){
        response = Serial.readStringUntil('\n');
    }
    return response;
}

void PiWrapper::sendData(String data, String type) {
    // TODO: implement
    // Send data to the pi
    // TODO: Define a set of standardized types that the pi will interpret
    // returns "success" or "error"
    ;
}

String PiWrapper::getData(String request) {
    // TODO: implement
    // Get data from the pi
    // TODO: Define a set of standardized requests that the pi will interpret
    ;
}
