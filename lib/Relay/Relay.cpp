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
  String data = mode + sep + name;
  createQuery("post", data, type);
  sendQuery();
}

void Relay::getInterval() {} // TODD

void Relay::getOnTime() {} // TODO
