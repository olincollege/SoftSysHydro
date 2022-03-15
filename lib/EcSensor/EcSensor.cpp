#include <Ezo_uart.h>
#include "EcSensor.h"

EcSensor::EcSensor()
{
  static Ezo_uart Module(Serial3);
  module = &Module;
}

void EcSensor::getReading()
{
  module->send_read();
  ec = module->get_reading();
}

bool EcSensor::isBelowRange()
{
  return ec < minEc;
}

void EcSensor::sendSensorLog()
{
  Query q = {
      "sensor",
      "post",
      "ec",
      (String)ec};
  createQuery(q);
  sendQuery();
  String response = getResponse();
}

void EcSensor::getMinEc()
{
  Query q = {
      "system",
      "get",
      "ecMin",
      "1"};
  createQuery(q);
  sendQuery();
  String response = getResponse();
  if (response != "")
  {
    minEc = response.toDouble();
  }
}

void EcSensor::getInterval()
{
  Query q = {
      "system",
      "get",
      "ecSenseInterval",
      "1"};
  createQuery(q);
  sendQuery();
  String response = getResponse();
  if (response != "")
  {
    interval = response.toInt();
  }
}