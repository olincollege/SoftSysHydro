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
            while (Serial.available() > 0)
            {
                Serial.read();
            }
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

void PiWrapper::createQuery(Query q)
{
    query = q.dataType + sep + q.reqType + sep + q.sensorName + sep + q.data;
}

void PiWrapper::sendQuery()
{
    Serial.println(query);
}
