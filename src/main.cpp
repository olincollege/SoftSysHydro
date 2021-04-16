#include <Arduino.h>
#include <PhSensor.h>
#include <PhPump.h>
#include <ph_grav.h>
#include <Temperature.h>
#include <ECSensor.h>
PhSensor phSensor(A0);
Gravity_pH grav_ph_sensor(A0);
Temperature temperature(A1);
ECSensor ecSensor;

void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);
  unsigned long startTime = millis()/1000;
  PhSensor phSensor(A0);
  phSensor.getInterval();
  phSensor.getMaxPh();
  phSensor.lastReading = startTime;
  PhPump phPump(A1);
  phPump.lastDispense = startTime;
  phPump.getInterval();
  Temperature temperature(A2);
  temperature.lastReading = startTime;
  temperature.getInterval();
  
  while (true) {
    delay(5000);

    ecSensor.sendSensorLog();

    unsigned long elapsedSeconds = millis()/1000;
    if (elapsedSeconds-phSensor.lastReading > phSensor.interval) {
        phSensor.sendSensorLog();
        phSensor.lastReading = millis()/1000;
    }
    if (elapsedSeconds-temperature.lastReading > temperature.interval) {
        temperature.sendSensorLog();
        temperature.lastReading = millis()/1000;
    }
    if (elapsedSeconds-phPump.lastDispense > phPump.interval) {
        if (phSensor.aboveRange()) {
            phPump.dispense();
            phPump.sendLog();
        }
        phPump.lastDispense = millis()/1000;
    }
  }


}