#include <Arduino.h>
#include <PhSensor.h>
#include <PhPump.h>
#include <ph_grav.h>
#include <Temperature.h>
#include <ECSensor.h>
#include <EcPump.h>

PhSensor phSensor(A0);
PhPump phPump(A2);
Temperature temperature(A1);
ECSensor ecSensor;
EcPump ecPump(A3, A4, A5);
long getParamsInterval = 3600;
long lastGetParams;

unsigned long seconds()
{
  long divisor = 1000;
  return millis() / divisor;
}

void updateParams()
{
  ecSensor.getInterval();
  ecSensor.getMinEC();
  temperature.getInterval();
  phPump.getInterval();
  phPump.getDispenseTime();
  phSensor.getInterval();
  phSensor.getMaxPh();
  ecPump.getInterval();
  ecPump.getDispenseTime();
  lastGetParams = seconds();
}

void setup()
{
  Serial.begin(9600);
  delay(1000);
  //Serial3.begin(9600);
  phSensor.lastReading = seconds();
  phPump.lastDispense = seconds();
  temperature.lastReading = seconds();
  ecSensor.lastReading = seconds();
  updateParams();
}

void loop()
{
  delay(5000);
  
  unsigned long elapsedSeconds = seconds();
  if (elapsedSeconds - phSensor.lastReading > phSensor.interval)
  {
    phSensor.sendSensorLog();
    phSensor.lastReading = seconds();
  }
  if (elapsedSeconds - temperature.lastReading > temperature.interval)
  {
    temperature.sendSensorLog();
    temperature.lastReading = seconds();
  }
  if (elapsedSeconds - phPump.lastDispense > phPump.interval)
  {
    if (phSensor.aboveRange())
    {
      phPump.dispense();
      phPump.sendLog();
    }
    phPump.lastDispense = seconds();
  }
  if (elapsedSeconds - phPump.lastDispense > phPump.interval)
  {
    if (ecSensor.aboveRange()) {
      ecPump.dispense();
      ecPump.sendLog();
    }
    ecPump.lastDispense = seconds();
  }
  if (elapsedSeconds - ecSensor.lastReading > ecSensor.interval)
  {
    ecSensor.sendSensorLog();
    ecSensor.getInterval();
    ecSensor.lastReading = seconds();
  }
  if (elapsedSeconds - lastGetParams > getParamsInterval)
  {
    updateParams();
    lastGetParams = seconds();
  }
}