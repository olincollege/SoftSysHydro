#include "PiWrapper.h"

char* PiWrapper::sendData(int data, char* type) {
    char reqType[] = ":post:";
    Serial.print(type);
    Serial.print(reqType);
    Serial.print(data);
    Serial.print("\n");
    unsigned long StartTime = millis();
    char response[] = "waiting";
    while (true){
        unsigned long CurrentTime = millis();
        unsigned long ElapsedTime = CurrentTime - StartTime;
        if (Serial.available() > 0){
            Serial.readStringUntil('\n').toCharArray(response, 50);
            break;
        } else if (ElapsedTime > 5000){
            break;
        }
    }
    return response;
}

char* PiWrapper::sendData(char* data, char* type) {
    char *reqType = ":post:";
    Serial.print(type);
    Serial.print(reqType);
    Serial.print(data);
    Serial.print("\n");
    unsigned long StartTime = millis();
    char response[] = "waiting";
    while (true){
        unsigned long CurrentTime = millis();
        unsigned long ElapsedTime = CurrentTime - StartTime;
        if (Serial.available() > 0){
            Serial.readStringUntil('\n').toCharArray(response, 50);
            break;
        } else if (ElapsedTime > 5000){
            break;
        }
    }
    return response;
}

char* PiWrapper::getData(char* request) {
    char reqType[] = ":get:";
    Serial.print(reqType);
    Serial.print(request);
    Serial.print("\n");
    char response[] = "waiting";
    unsigned long StartTime = millis();
    while (true){
        unsigned long CurrentTime = millis();
        unsigned long ElapsedTime = CurrentTime - StartTime;
        if (Serial.available() > 0){
            Serial.readStringUntil('\n').toCharArray(response, 50);
            break;
        } else if (ElapsedTime > 5000){
            break;
        }
    }
    return response;
}
