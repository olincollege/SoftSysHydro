#include <PhSensor.h>
#include <unity.h>

PhSensor phSensor(A0);

void test_get_reading() {
    phSensor.getReading();
    TEST_ASSERT_TRUE(phSensor.ph > 0.0);
}

void test_is_above_range() {
    phSensor.ph = 100;
    TEST_ASSERT_EQUAL(true, phSensor.isAboveRange());
    phSensor.ph = 0;
    TEST_ASSERT_EQUAL(false, phSensor.isAboveRange());
}

void test_send_sensor_log() {
    phSensor.ph = 1.10;
    phSensor.sendSensorLog();
    TEST_ASSERT(phSensor.query == "ph:post:1.10\n")
}

void test_get_interval() {
    phSensor.getInterval();
    TEST_ASSERT(phSensor.query == "sensor_interval:get:system/1\n")
}

void test_get_max_ph() {
    phSensor.getMaxPh();
    TEST_ASSERT(phSensor.query == "ph_high:get:system/1\n")
}

int main() {
    phSensor.timeout = 0;
    UNITY_BEGIN();
    RUN_TEST(test_get_reading);
    RUN_TEST(test_is_above_range);
    RUN_TEST(test_send_sensor_log);
    RUN_TEST(test_get_interval);
    RUN_TEST(test_get_max_ph);
    UNITY_END();
    return 0;
}