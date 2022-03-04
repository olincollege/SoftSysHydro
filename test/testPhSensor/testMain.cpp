#include <PhSensor.h>
#include <unity.h>

PhSensor phSensor(A0);

void testGetReading()
{
    phSensor.getReading();
    Serial.println(phSensor.ph);
    TEST_ASSERT(phSensor.ph > 0.0 && phSensor.ph < 15);
}

void testIsAboveRange()
{
    phSensor.ph = 100;
    TEST_ASSERT_EQUAL(true, phSensor.isAboveRange());
    phSensor.ph = 0;
    TEST_ASSERT_EQUAL(false, phSensor.isAboveRange());
}

void testSendSensorLog()
{
    phSensor.ph = 1.10;
    phSensor.sendSensorLog();
    TEST_ASSERT(phSensor.query == "sensor:post:ph:1.10")
}

void testGetInterval()
{
    phSensor.timeout = 0;
    phSensor.getInterval();
    TEST_ASSERT(phSensor.query == "system:get:phSensorInterval:1")
}

void testGetMaxPh()
{
    phSensor.timeout = 0;
    phSensor.getMaxPh();
    TEST_ASSERT(phSensor.query == "system:get:phMax:1")
}

void setup()
{
    UNITY_BEGIN();
    RUN_TEST(testGetReading);
    RUN_TEST(testIsAboveRange);
    RUN_TEST(testSendSensorLog);
    RUN_TEST(testGetInterval);
    RUN_TEST(testGetMaxPh);
    UNITY_END();
}

void loop()
{
    ;
}