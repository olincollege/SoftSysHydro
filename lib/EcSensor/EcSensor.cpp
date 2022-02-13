#include <Ezo_uart.h>
#include "EcSensor.h"

EcSensor::EcSensor(HardwareSerial serial) {
  static Ezo_uart Module(serial, "EC");
  this->module = &Module;
}

void EcSensor::getReading() {
  Serial.println("Getting reading");
  this->module->send_read();
  Serial.println("sent");
  ec = this->module->get_reading();
}

bool EcSensor::belowRange() {
  return this->ec < this->minEc;
}

void EcSensor::sendSensorLog() {
  String query = createQuery("post", this->ec, this->type);
  sendQuery(query);
}

void EcSensor::getMinEc() {
  String query = createQuery("get", this->systemId, "ec_low");
  String response = getResponse();
  if (response != "") {
      this->minEc = response.toDouble();
  }
}

void EcSensor::getInterval() {
  String query = createQuery("get", this->systemId, "sensor_interval");
  String response = getResponse();
  if (response != "") {
      int intervalInt = response.toInt();
      this->interval = long(intervalInt);
  }
}