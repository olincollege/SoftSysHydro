#include <Ezo_uart.h>
#include "EcSensor.h"

EcSensor::EcSensor()
{
  static Ezo_uart Module(Serial3, "EC");
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
  query = createQuery("post", ec, type);
  sendQuery(query);
}

void EcSensor::getMinEc()
{
  query = createQuery("get", systemId, "ec_low");
  String response = getResponse();
  if (response != "")
  {
    minEc = response.toDouble();
  }
}

void EcSensor::getInterval()
{
  query = createQuery("get", systemId, "sensor_interval");
  String response = getResponse();
  if (response != "")
  {
    int intervalInt = response.toInt();
    interval = long(intervalInt);
  }
}