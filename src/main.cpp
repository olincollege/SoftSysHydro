#include "PhSensor.h"
#include "EcSensor.h"
#include <RTClib.h>

// Create ph sensor object
PhSensor phSensor(A0);
EcSensor ecSensor; // Constructs on Serial3
RTC_DS3231 rtc;

void setup()
{
  Serial.begin(9600);
  Serial.println("s");
  Serial3.begin(9600);
  if (!rtc.begin())
  {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1)
      delay(10);
  }
  delay(1000);
  rtc.adjust(DateTime(2022, 1, 1, 1, 0, 0));
  DateTime now = rtc.now();
  phSensor.lastReading = now;
  ecSensor.lastReading = now;
  phSensor.interval = 10;
  ecSensor.interval = 10;
}

bool isPassedSensorInterval(DateTime now, int interval, DateTime lastReading)
{
  DateTime dispTime = lastReading + TimeSpan(interval);
  return (dispTime < now);
}

void loop()
{
  DateTime now = rtc.now();
  if (isPassedSensorInterval(now, phSensor.interval, phSensor.lastReading))
  {
    phSensor.getReading();
    phSensor.sendSensorLog();
    phSensor.lastReading = rtc.now();
    delay(5000);
  }
  if (isPassedSensorInterval(now, ecSensor.interval, ecSensor.lastReading))
  {
    ecSensor.getReading();
    ecSensor.sendSensorLog();
    ecSensor.lastReading = rtc.now();
    delay(5000);
  }
  delay(2000);
}