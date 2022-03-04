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
  q = {
      "sensor",
      "post",
      "ec",
      (String)ec};
  sendQuery();
}

void EcSensor::getMinEc()
{
  q = {
      "system",
      "get",
      "ecMin",
      "1"};
  sendQuery();
  String response = getResponse();
  if (response != "")
  {
    minEc = response.toDouble();
  }
}

void EcSensor::getInterval()
{
  q = {
      "system",
      "get",
      "ecSensorInterval",
      "1"};
  sendQuery();
  String response = getResponse();
  if (response != "")
  {
    interval = response.toInt();
  }
}