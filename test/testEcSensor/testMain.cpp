#include <EcSensor.h>
#include <unity.h>

EcSensor ecSensor;

void testGetReading()
{
  ecSensor.getReading();
  Serial.println(ecSensor.ec);
  TEST_ASSERT(ecSensor.ec > -0.01 && ecSensor.ec < 1500);
}

void testIsBelowRange()
{
  ecSensor.ec = 1000;
  TEST_ASSERT(!ecSensor.isBelowRange());
  ecSensor.ec = 0;
  TEST_ASSERT(ecSensor.isBelowRange());
}

void testSendSensorLog()
{
  ecSensor.ec = 600.00;
  ecSensor.timeout = 0;
  ecSensor.sendSensorLog();
  TEST_ASSERT(ecSensor.query.equals("sensor:post:ec:600.00"));
}

void testGetInterval()
{
  ecSensor.timeout = 0;
  ecSensor.getInterval();
  TEST_ASSERT(ecSensor.query.equals("system:get:ecSenseInterval:1"));
}

void testGetMinEc()
{
  ecSensor.timeout = 0;
  ecSensor.getMinEc();
  TEST_ASSERT(ecSensor.query.equals("system:get:ecMin:1"));
}

void setup()
{
  UNITY_BEGIN();
  RUN_TEST(testGetReading);
  RUN_TEST(testIsBelowRange);
  RUN_TEST(testSendSensorLog);
  RUN_TEST(testGetInterval);
  RUN_TEST(testGetMinEc);
  UNITY_END();
}

void loop()
{
  ;
}