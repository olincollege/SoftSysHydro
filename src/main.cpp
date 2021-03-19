#include <Arduino.h>
#include <PhSensor.h>
#include <PhUpPump.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  PhSensor phSensor;
  phSensor.ph = 7;
  phSensor.sendSensorLog();
  delay(3000);
  // put your main code here, to run repeatedly:
}