#include <TempSensor.h>
#include <unity.h>

TempSensor tempSensor(A2);

void test_get_reading()
{
  tempSensor.getReading();
  Serial.println(tempSensor.temp);
  TEST_ASSERT(tempSensor.temp > 10.0 && tempSensor.temp < 35.0);
}

void test_calc_res()
{
  tempSensor.analogReading = 550;
  tempSensor.calcRes();
  Serial.println(tempSensor.resistance);
  float expected = 12790.70;
  TEST_ASSERT(abs(tempSensor.resistance - expected) < 0.01);
}

void test_calc_temp()
{
  tempSensor.resistance = 10000;
  tempSensor.calcTemp();
  Serial.println(tempSensor.temp);
  TEST_ASSERT(tempSensor.temp == 25.00);
}

void test_send_sensor_log()
{
  tempSensor.temp = 20.50;
  tempSensor.sendSensorLog();
  TEST_ASSERT(tempSensor.query == "sensor:post:temp:20.50")
}

void test_get_interval()
{
  tempSensor.timeout = 0;
  tempSensor.getInterval();
  TEST_ASSERT(tempSensor.query == "system:get:tempSensorInterval:1")
}

void setup()
{
  UNITY_BEGIN();
  RUN_TEST(test_get_reading);
  RUN_TEST(test_calc_res);
  RUN_TEST(test_calc_temp);
  RUN_TEST(test_send_sensor_log);
  RUN_TEST(test_get_interval);
  UNITY_END();
}

void loop()
{
  ;
}