#include "Relay.h"

Relay::Relay(int digitalPin, String relayName)
{
  pin = digitalPin;
  name = relayName;
  pinMode(pin, OUTPUT);
}

void Relay::On()
{
  digitalWrite(pin, HIGH);
}

void Relay::Off()
{
  digitalWrite(pin, LOW);
}

void Relay::sendTaskLog(int mode)
{
  q = {
      "task",
      "post",
      name,
      (String)mode};
  sendQuery();
  String response = getResponse();
}

void Relay::getInterval()
{
  q = {
      "system",
      "get",
      name + "TaskInterval",
      "1"};
  sendQuery();
  String response = getResponse();
  if (response != "")
  {
    interval = response.toInt();
  }
}

void Relay::getOnTime()
{
  q = {
      "system",
      "get",
      name + "TaskLength",
      "1"};
  sendQuery();
  String response = getResponse();
  if (response != "")
  {
    onTime = response.toInt();
  }
}
