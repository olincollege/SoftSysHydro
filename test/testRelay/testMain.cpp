#include <Relay.h>
#include <unity.h>

Relay relay(A2, "ph");

void testGetInterval()
{
  relay.getInterval();
  TEST_ASSERT(relay.query == "system:get:phTaskInterval:1")
}

void testGetOnTime()
{
  relay.getOnTime();
  TEST_ASSERT(relay.query == "system:get:phTaskLength:1")
}

void testSendTaskLog()
{
  relay.sendTaskLog(1);
  TEST_ASSERT(relay.query == "task:post:ph:1")
}

void setup()
{
  UNITY_BEGIN();
  RUN_TEST(testGetInterval);
  RUN_TEST(testGetOnTime);
  RUN_TEST(testSendTaskLog);
  UNITY_END();
}

void loop()
{
  ;
}