#include <Arduino.h>
#include <PhSensor.h>
#include <PhPump.h>
#include <ph_grav.h>
#include <Temperature.h>
PhSensor phSensor(A0);
Gravity_pH grav_ph_sensor(A0);
Temperature temperature(A1);

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  delay(5000);
  PhSensor phSensor(A0);
  // phSensor.getReading();
  phSensor.ph = 7;
  phSensor.sendSensorLog();
  
  temperature.getTemp();
  Serial.print("temp: post: ");
  Serial.println(temperature.temperature);
  //temperature.sendSensorLog();
  delay(1000);
  // put your main code here, to run repeatedly:
}