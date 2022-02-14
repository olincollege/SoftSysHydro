#include <PhSensor.h>
#include <EcSensor.h>

// Create ph sensor object
PhSensor phSensor(A0);
EcSensor ecSensor; // Constructs on Serial3

// Returns the time since the arduino has been powered
// on in units of seconds
unsigned long seconds()
{
  long divisor = 1000;
  return millis() / divisor;
}

void setup()
{
  Serial.begin(9600);
  Serial3.begin(9600);
  delay(1000);
  phSensor.lastReading = seconds();
  ecSensor.lastReading = seconds();
  phSensor.interval = 10;
  ecSensor.interval = 10;
}

void loop()
{
  delay(3000);
  unsigned long elapsedSeconds = seconds();
  // If enough time has elapsed since the last reading
  // then take a sensor reading and reset lastReading
  if (elapsedSeconds - phSensor.lastReading > phSensor.interval)
  {
    phSensor.getReading();
    phSensor.sendSensorLog();
    phSensor.lastReading = seconds();
    delay(5000);
  }
  if (elapsedSeconds - ecSensor.lastReading > ecSensor.interval)
  {
    ecSensor.getReading();
    ecSensor.sendSensorLog();
    ecSensor.lastReading = seconds();
    delay(5000);
  }
}