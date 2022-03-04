#include <TempSensor.h>
#include <unity.h>

TempSensor tempSensor(A2);

void testGetReading()
{
  tempSensor.getReading();
  Serial.println(tempSensor.temp);
  TEST_ASSERT(tempSensor.temp > 10.0 && tempSensor.temp < 35.0);
}

void testCalcRes()
{
  tempSensor.analogReading = 550;
  tempSensor.calcRes();
  Serial.println(tempSensor.resistance);
  float expected = 12790.70;
  TEST_ASSERT(abs(tempSensor.resistance - expected) < 0.01);
}

void testCalcTemp()
{
  tempSensor.resistance = 10000;
  tempSensor.calcTemp();
  Serial.println(tempSensor.temp);
  TEST_ASSERT(tempSensor.temp == 25.00);
}

void testSendSensorLog()
{
  tempSensor.temp = 20.50;
  tempSensor.sendSensorLog();
  TEST_ASSERT(tempSensor.query == "sensor:post:temp:20.50")
}

void testGetInterval()
{
  tempSensor.timeout = 0;
  tempSensor.getInterval();
  TEST_ASSERT(tempSensor.query == "system:get:tempSensorInterval:1")
}

void setup()
{
  UNITY_BEGIN();
  RUN_TEST(testGetReading);
  RUN_TEST(testCalcRes);
  RUN_TEST(testCalcTemp);
  RUN_TEST(testSendSensorLog);
  RUN_TEST(testGetInterval);
  UNITY_END();
}

void loop()
{
  ;
}