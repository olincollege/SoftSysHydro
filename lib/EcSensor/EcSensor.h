#ifndef ECSENSOR_H
#define ECSENSOR_H
#include "PiWrapper.h"
#include <Ezo_uart.h>

class EcSensor : public PiWrapper
{
public:
  float ec = 0.0;
  unsigned long interval = 120;
  String type = "ec";
  unsigned long lastReading;
  float minEc = 200;
  EcSensor();
  Ezo_uart *module;
  // Get a reading and update ec
  void getReading();
  // Check if ec reading is above range
  bool isBelowRange();
  // Send latest sensor reading to pi via wrapper
  void sendSensorLog();
  // Gets max EC from pi via wrapper
  // Updates: maxEc data member
  void getMinEc();
  // Get dispense interval from pi via wrapper
  // Updates: interval data member
  void getInterval();
};

#endif