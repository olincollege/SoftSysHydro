#include <PhSensor.h>
#include <unity.h>

PhSensor phSensor(A0);

void test_get_reading()
{
    phSensor.getReading();
    Serial.println(phSensor.ph);
    TEST_ASSERT(phSensor.ph > 0.0 && phSensor.ph < 15);
}

void test_is_above_range()
{
    phSensor.ph = 100;
    TEST_ASSERT_EQUAL(true, phSensor.isAboveRange());
    phSensor.ph = 0;
    TEST_ASSERT_EQUAL(false, phSensor.isAboveRange());
}

void test_send_sensor_log()
{
    phSensor.ph = 1.10;
    phSensor.sendSensorLog();
    TEST_ASSERT(phSensor.query == "sensor:post:ph:1.10")
}

void test_get_interval()
{
    phSensor.timeout = 0;
    phSensor.getInterval();
    TEST_ASSERT(phSensor.query == "system:get:phSensorInterval:1")
}

void test_get_max_ph()
{
    phSensor.timeout = 0;
    phSensor.getMaxPh();
    TEST_ASSERT(phSensor.query == "system:get:phMax:1")
}

void setup()
{
    UNITY_BEGIN();
    RUN_TEST(test_get_reading);
    RUN_TEST(test_is_above_range);
    RUN_TEST(test_send_sensor_log);
    RUN_TEST(test_get_interval);
    RUN_TEST(test_get_max_ph);
    UNITY_END();
}

void loop()
{
    ;
}