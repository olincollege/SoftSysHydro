#include <PhSensor.h>
#include <EcSensor.h>

// Create ph sensor object
PhSensor phSensor(A0);
EcSensor ecSensor(Serial3);

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
  Serial.println("Setup complete");
}

void loop()
{
  delay(5000);
  Serial.println("test");
  ecSensor.getReading();
  Serial.println(ecSensor.ec);
  delay(10000000);
  unsigned long elapsedSeconds = seconds();
  // If enough time has elapsed since the last reading
  // then take a sensor reading and reset lastReading
  if (elapsedSeconds - phSensor.lastReading > phSensor.interval)
  {
    phSensor.sendSensorLog();
    phSensor.lastReading = seconds();
  }
}