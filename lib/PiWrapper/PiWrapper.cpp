#include "PiWrapper.h"

char* PiWrapper::sendData(int data, char* type) {
    char *response = "waiting";
    char *reqType = ":post:";
    Serial.print(type);
    Serial.print(reqType);
    Serial.print(data);
    Serial.print("\n");
    while (response == "waiting"){
        Serial.readStringUntil('\n').toCharArray(response, 50);
    }
    return response;
}

char* PiWrapper::sendData(char* data, char* type) {
    char *response = "waiting";
    char *reqType = ":post:";
    Serial.print(type);
    Serial.print(reqType);
    Serial.print(data);
    Serial.print("\n");
    while (response == "waiting"){
        Serial.readStringUntil('\n').toCharArray(response, 50);
    }
    return response;
}

char* PiWrapper::getData(char* request) {
    char *response = "waiting";
    char *reqType = ":get:";
    Serial.print(reqType);
    Serial.print(request);
    Serial.print("\n");
    while (response == "waiting"){
        Serial.readStringUntil('\n').toCharArray(response, 50);
    }
    return response;
}
