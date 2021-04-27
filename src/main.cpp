#include <Arduino.h>
#include <PhSensor.h>
#include <PhPump.h>
#include <ph_grav.h>
#include <Temperature.h>
#include <ECSensor.h>

PhSensor phSensor(A0);
PhPump phPump(A2);
Temperature temperature(A1);
ECSensor ecSensor;
long getParamsInterval = 3600;
long lastGetParams;

unsigned long seconds()
{
  return millis() / 1000;
}

void updateParams()
{
  ecSensor.getInterval();
  ecSensor.getMinEC();
  temperature.getInterval();
  phPump.getInterval();
  phSensor.getInterval();
  phSensor.getMaxPh();
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
  if (elapsedSeconds - ecSensor.lastReading > ecSensor.interval)
  {
    //ecSensor.sendSensorLog();
    ecSensor.getInterval();
    ecSensor.lastReading = seconds();
  }
  if (elapsedSeconds - lastGetParams > getParamsInterval)
  {
    updateParams();
  }
}