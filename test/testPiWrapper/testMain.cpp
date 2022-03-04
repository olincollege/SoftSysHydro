#include <PiWrapper.h>
#include <unity.h>

PiWrapper wrapper = PiWrapper();

void testCreateQueryStr()
{
  wrapper.q = {
      "sensor",
      "post",
      "ph",
      "7.1"};
  wrapper.createQuery();
  TEST_ASSERT(wrapper.query == "sensor:post:ph:7.1");
}

void testHasTimedOutTrue()
{
  wrapper.timeout = 0;
  unsigned long startTime = millis();
  bool t = wrapper.hasTimedOut(startTime);
  TEST_ASSERT(t);
}

void testHasTimedOutFalse()
{
  wrapper.timeout = 1000;
  unsigned long startTime = millis();
  bool t = wrapper.hasTimedOut(startTime);
  TEST_ASSERT(!t);
}

void setup()
{
  UNITY_BEGIN();
  RUN_TEST(testCreateQueryStr);
  RUN_TEST(testHasTimedOutTrue);
  RUN_TEST(testHasTimedOutFalse);
  UNITY_END();
}

void loop()
{
  ;
}