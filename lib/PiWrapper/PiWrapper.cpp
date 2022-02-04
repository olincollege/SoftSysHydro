#include "PiWrapper.h"

unsigned long timeout = 5000;

String getResponse() {
    unsigned long StartTime = millis();
    String response = "";
    while (true){
        unsigned long CurrentTime = millis();
        unsigned long ElapsedTime = CurrentTime - StartTime;
        if (Serial.available() > 0){
            response = Serial.readString();
            break;
        } else if (ElapsedTime > timeout){
            break;
        }
    }
    return response;
}

String PiWrapper::sendData(double data, String type) {
    String reqType = ":post:";
    Serial.print(type);
    Serial.print(reqType);
    Serial.println(data);
    return getResponse();
}

String PiWrapper::sendData(String data, String type) {
    String reqType = ":post:";
    Serial.print(type);
    Serial.print(reqType);
    Serial.println(data);
    return getResponse();
}

String PiWrapper::getData(String request, String type) {
    String reqType = ":get:";
    Serial.print(type);
    Serial.print(reqType);
    Serial.println(request);
    return getResponse();
}
