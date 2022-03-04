#include "PiWrapper.h"

class Relay : public PiWrapper
{
public:
  int pin;
  int interval;
  int onTime;
  const String type = "task";
  String name;
  DateTime lastOn;
  DateTime lastOff;
  Relay(int digitalPin, String relayName);
  // Turn relay on
  void On();
  // Turn relay off
  void Off();
  // Send a log of relay going on or off
  void sendTaskLog(int mode);
  // Get interval to check and turn on
  void getInterval();
  // Get amount of time to stay on
  void getOnTime();
};