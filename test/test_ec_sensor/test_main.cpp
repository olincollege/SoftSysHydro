#include <EcSensor.h>
#include <unity.h>

EcSensor ecSensor;

void test_get_reading()
{
  ecSensor.getReading();
  Serial.println(ecSensor.ec);
  TEST_ASSERT(ecSensor.ec > 0.0 && ecSensor.ec < 1500);
}

void test_is_below_range()
{
  ecSensor.ec = 1000;
  TEST_ASSERT(!ecSensor.isBelowRange());
  ecSensor.ec = 0;
  TEST_ASSERT(ecSensor.isBelowRange());
}

void test_send_sensor_log()
{
  ecSensor.ec = 600.00;
  ecSensor.sendSensorLog();
  Serial.println(ecSensor.query);
  TEST_ASSERT(ecSensor.query == "ec:post:600.00\n")
}

void test_get_interval()
{
  ecSensor.timeout = 0;
  ecSensor.getInterval();
  TEST_ASSERT(ecSensor.query == "sensor_interval:get:system/1\n")
}

void test_get_min_ec()
{
  ecSensor.timeout = 0;
  ecSensor.getMinEc();
  TEST_ASSERT(ecSensor.query == "ec_low:get:system/1\n")
}

void setup()
{
  UNITY_BEGIN();
  RUN_TEST(test_get_reading);
  RUN_TEST(test_is_below_range);
  RUN_TEST(test_send_sensor_log);
  RUN_TEST(test_get_interval);
  RUN_TEST(test_get_min_ec);
  UNITY_END();
}

void loop()
{
  ;
}