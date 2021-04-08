#include <Arduino.h>
#include <PhSensor.h>
#include <PhPump.h>
#include <ph_grav.h>

Gravity_pH pH = A0; //Assigns pin for pH signal

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(5000);
  PhSensor phSensor(A0);
  phSensor.ph = 7;
  phSensor.sendSensorLog();
  // put your main code here, to run repeatedly:
}