#include <PiWrapper.h>
#include <unity.h>

PiWrapper wrapper = PiWrapper();

void test_create_query_str()
{
  wrapper.q = {
      "sensor",
      "post",
      "ph",
      "7.1"};
  wrapper.createQuery();
  TEST_ASSERT(wrapper.query == "sensor:post:ph:7.1");
}

void test_has_timed_out_true()
{
  wrapper.timeout = 0;
  unsigned long startTime = millis();
  bool t = wrapper.hasTimedOut(startTime);
  TEST_ASSERT(t);
}

void test_has_timed_out_false()
{
  wrapper.timeout = 1000;
  unsigned long startTime = millis();
  bool t = wrapper.hasTimedOut(startTime);
  TEST_ASSERT(!t);
}

void setup()
{
  UNITY_BEGIN();
  RUN_TEST(test_create_query_str);
  RUN_TEST(test_has_timed_out_true);
  RUN_TEST(test_has_timed_out_false);
  UNITY_END();
}

void loop()
{
  ;
}