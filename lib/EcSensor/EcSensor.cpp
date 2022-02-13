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
  createQuery("post", ec, type);
  sendQuery();
}

void EcSensor::getMinEc()
{
  createQuery("get", systemId, "ec_low");
  sendQuery();
  String response = getResponse();
  if (response != "")
  {
    minEc = response.toDouble();
  }
}

void EcSensor::getInterval()
{
  createQuery("get", systemId, "sensor_interval");
  sendQuery();
  String response = getResponse();
  if (response != "")
  {
    int intervalInt = response.toInt();
    interval = long(intervalInt);
  }
}