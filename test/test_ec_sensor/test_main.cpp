#include <EcSensor.h>
#include <unity.h>

EcSensor ecSensor;

void test_get_reading()
{
  ecSensor.getReading();
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
  TEST_ASSERT(ecSensor.query.equals("ec:post:600.00"));
}

void test_get_interval()
{
  ecSensor.timeout = 0;
  ecSensor.getInterval();
  TEST_ASSERT(ecSensor.query.equals("sensor_interval:get:system/1"));
}

void test_get_min_ec()
{
  ecSensor.timeout = 0;
  ecSensor.getMinEc();
  TEST_ASSERT(ecSensor.query.equals("ec_low:get:system/1"));
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