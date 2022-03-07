#include "PiWrapper.h"

String PiWrapper::getResponse()
{
    uint64_t startTime = millis();
    String response = "";
    while (true)
    {
        if (Serial.available() > 0)
        {
            response = Serial.readStringUntil('\n');
            break;
        }
        else if (hasTimedOut(startTime))
            break;
    }
    return response;
}

bool PiWrapper::hasTimedOut(uint64_t startTime)
{
    uint64_t elapsedTime = millis() - startTime;
    return elapsedTime >= this->timeout;
}

void PiWrapper::createQuery()
{
    query = q.dataType + sep + q.reqType + sep + q.sensorName + sep + q.data;
}

void PiWrapper::sendQuery()
{
    createQuery();
    Serial.println(query);
}
