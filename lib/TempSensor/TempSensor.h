#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H
#include "PiWrapper.h"

class TempSensor : public PiWrapper
{
public:
  const String type = "temp";
  const int numSamples = 5;
  const int seriesResistor = 11000;
  const int bco = 3950;
  const int thermRes = 10000;
  const int tempNom = 25;
  DateTime lastReading;
  float temp = 0.0;
  float analogReading = 0.0;
  float resistance = 0.0;
  unsigned int interval = 120;
  uint8_t pin;
  // Constructor
  TempSensor(uint8_t analogPin);
  // Get temp readings from sensor
  // Updates: temp data member
  void getReading();
  // Send latest sensor reading to pi via wrapper
  void sendSensorLog();
  // Get reading interval from pi via wrapper
  // Updates: interval data member
  void getInterval();
  // Calculate resistance from analogReading
  // Updates: resistance data member
  void calcRes();
  // Calculates temperature from resistance
  // Updates: temp data member
  void calcTemp();
};
#endif