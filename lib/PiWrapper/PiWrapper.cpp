#include "PiWrapper.h"

unsigned long timeout = 5000;


String PiWrapper::sendData(double data, String type) {
    String reqType = ":post:";
    Serial.print(type);
    Serial.print(reqType);
    Serial.print(data);
    Serial.print("|||");
    unsigned long StartTime = millis();
    String response = "";
    while (true){
        unsigned long CurrentTime = millis();
        unsigned long ElapsedTime = CurrentTime - StartTime;
        if (Serial.available() > 0){
            response = Serial.readStringUntil('|||');
            break;
        } else if (ElapsedTime > timeout){
            break;
        }
    }
    return response;
}

String PiWrapper::sendData(String data, String type) {
    String reqType = ":post:";
    Serial.print(type);
    Serial.print(reqType);
    Serial.print(data);
    Serial.print("|||");
    unsigned long StartTime = millis();
    String response = "";
    while (true){
        unsigned long CurrentTime = millis();
        unsigned long ElapsedTime = CurrentTime - StartTime;
        if (Serial.available() > 0){
            response = Serial.readStringUntil('|||');
            break;
        } else if (ElapsedTime > timeout){
            break;
        }
    }
    return response;
}

String PiWrapper::getData(String request, String type) {
    String reqType = ":get:";
    Serial.print(type);
    Serial.print(reqType);
    Serial.print(request);
    Serial.print("|||");
    String response = "";
    unsigned long StartTime = millis();
    while (true){
        unsigned long CurrentTime = millis();
        unsigned long ElapsedTime = CurrentTime - StartTime;
        if (Serial.available() > 0){
            response = Serial.readStringUntil('|||');
            break;
        } else if (ElapsedTime > timeout){
            break;
        }
    }
    return response;
}
