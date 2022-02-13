#include "PiWrapper.h"

String PiWrapper::getResponse()
{
    unsigned long startTime = millis();
    String response = "";
    while (true)
    {
        if (Serial.available() > 0)
        {
            response = Serial.readString();
            break;
        }
        else if (hasTimedOut(startTime))
            break;
    }
    return response;
}

bool PiWrapper::hasTimedOut(unsigned long startTime)
{
    unsigned long elapsedTime = millis() - startTime;
    return elapsedTime >= this->timeout;
}

void PiWrapper::createQuery(String reqType, String data, String type)
{
    query = type + sep + reqType + sep + data;
}

void PiWrapper::createQuery(String reqType, float data, String type)
{
    query = type + sep + reqType + sep + data;
}

void PiWrapper::sendQuery()
{
    Serial.println(query);
}
