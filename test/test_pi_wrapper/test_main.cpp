#include <PiWrapper.h>
#include <unity.h>

PiWrapper wrapper = PiWrapper();

void test_create_query_str()
{
  wrapper.createQuery("req", "data", "type");
  TEST_ASSERT(wrapper.query == "type:req:data");
}

void test_create_query_dbl()
{
  wrapper.createQuery("req", 1.11, "type");
  TEST_ASSERT(wrapper.query == "type:req:1.11");
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
  RUN_TEST(test_create_query_dbl);
  RUN_TEST(test_has_timed_out_true);
  RUN_TEST(test_has_timed_out_false);
  UNITY_END();
}

void loop()
{
  ;
}