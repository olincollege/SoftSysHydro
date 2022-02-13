#include "PiWrapper.h"


String PiWrapper::getResponse() {
    unsigned long startTime = millis();
    String response = "";
    while (true){        
        if (this->serial.available() > 0){
            response = this->serial.readString();
            break;
        } else if (hasTimedOut(startTime)) break;
    }
    return response;
}

bool PiWrapper::hasTimedOut(unsigned long startTime){
    unsigned long elapsedTime = millis() - startTime;
    return elapsedTime >= this->timeout;
}

String PiWrapper::createQuery(String reqType, String data, String type) {
    return type + ":" + reqType + ":" + data + "\n";
}

String PiWrapper::createQuery(String reqType, double data, String type) {
    return type + ":" + reqType + ":" + data + "\n";
}

void PiWrapper::sendQuery(String query) {
    this->serial.print(query);
}
