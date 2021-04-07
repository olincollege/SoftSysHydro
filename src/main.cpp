#include <Arduino.h>
#include <PhSensor.h>
#include <PhPump.h>
#include <ph_grav.h>

Gravity_pH pH = A0; //Assigns pin for pH signal

void setup() {
  Serial.begin(9600);
}

void loop() {
  PhSensor phSensor(A0);
  phSensor.ph = 7;
  phSensor.sendSensorLog();
  //Serial.print("pH: ");
  //Serial.println(pH.read_ph());
  delay(10000);
  // put your main code here, to run repeatedly:
}