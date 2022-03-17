# Automated Hydroponics Garden

### Jonas Kazlauskas

## Project Goal

The goal of this project is to autonomously monitor and control a hydroponics garden with an Arduino. A hydroponics garden is a way of growing plants without soil using water that contains the nutrients that the plants need. This project aims to automate the task of checking and adjusting the pH and nutrient levels as well as turning the water pump on and off.

The lower bound is to make a program in c++ that integrates with a ph sensor, ec sensor, temperature sensor, and peristaltic pumps to control the system. The MVP will be done in an object oriented way and will include unit testing. A stretch goal will be to include relay outlet controls, a water level sensor, and a seperate standalone testing program. This is a project that was started in PINT's hydroponics subteam. There is currently code that has the ph sensor and ec sensor integrated that needs to be refactored. The starting version of this code can be found [here.](https://github.com/Olin-Hydro/circadia/commit/e49ae3136cc66cc65726b6823d3c179ce57df0de)

## Learning

In this project I want to develop my C++ skills and learn how to write my own libraries. I also want to explore unit testing and learn about how arduino libraries are implemented. Further, I want to consider things like memory management and the compilation process in my development.

## Resources

### General c/c++

- https://www.cplusplus.com/reference/
- Headfirst C
- https://www.w3schools.com/cpp/default.asp
- https://stackoverflow.com/
### Microcontroller specifics
- https://cdn.makezine.com/uploads/2014/03/make-avr-programming-chapter-two.pdf
- https://www.arduino.cc/reference/en/libraries/
- https://docs.platformio.org/en/latest/frameworks/arduino.html?utm_source=github&utm_medium=examples#examples

### Unit Testing

- https://tinkerman.cat/post/automated-unit-testing-metal
- https://docs.platformio.org/en/latest/plus/unit-testing.html

## Design

This project was created to work in the system shown below. On the left we have sensors and pumps that control the hydroponics garden. The firmware that was written for this project runs on the Arduino, and is responsible for interfacing with our harware to control the system. The Arduino sends and receives data over serial to a Raspberry Pi. The Raspberry Pi transforms serial data into api requests that stores the data in our Hydro API. The Arduino can also request data from the Raspberry Pi to adjust parameters of the system, like how often to take pH readings. 

![](https://codimd.s3.shivering-isles.com/demo/uploads/7ec70f1eb99ae6f0e09425181.png)


## Implementation

Each sensor or actuator has its own class that handles the hardware specific logic. An instance of each of these classes is created in the [main file](https://github.com/olincollege/SoftSysHydro/blob/main/src/main.cpp) where the control loop runs:

```c++
PhSensor phSensor(A0);
EcSensor ecSensor;
TempSensor tempSensor(A2);
Relay phDownPump(53, "ph");
Relay ecUpPump(52, "ec");
Relay waterPump(51, "water");
RTC_DS3231 rtc;
```

Control loop:

```c++
void loop()
{
  runPhSensor();
  runEcSensor();
  runTempSensor();
  runPhDownPump();
  runEcUpPump();
  runWaterPump();
  updateParams();
  delay(100);
}
```

As an example, the runPhSensor function is shown below:

```c
void runPhSensor()
{
  if (isPassedInterval(phSensor.interval, phSensor.lastReading))
  {
    phSensor.getReading();
    phSensor.sendSensorLog();
    phSensor.lastReading = rtc.now();
  }
}
```
This function checks if enough time has passed since the last reading was taken. If it is time to take a new reading, then it will get a reading and send that data to the Raspberry Pi. 

### TempSensor

Below is the implementation of the [temperature sensor class](https://github.com/olincollege/SoftSysHydro/tree/main/lib/TempSensor). This offers an example of how the other classes are written. The getReading function takes a temperature sensor reading and updates the temp data member. After this, the new value can be sent to the pi using sendSensorLog. This message would like something like this: ```sensor:post:temp:21.33```. Lastly, getInterval pulls data from our api through the pi to change how often a sensor reading is taken. There are a number of helper functions and constants as well that change the raw thermistor reading into a temperature.

```c++
class TempSensor : public PiWrapper
{
public:
  const String type = "temp";
  const int numSamples = 5;
  const int seriesResistor = 11000;
  const int bco = 3950;
  const int thermRes = 10000;
  const int tempNom = 25;
  DateTime lastReading;
  float temp = 0.0;
  float analogReading = 0.0;
  float resistance = 0.0;
  unsigned int interval = 120;
  uint8_t pin;
  // Constructor
  TempSensor(uint8_t analogPin);
  // Get temp readings from sensor
  // Updates: temp data member
  void getReading();
  // Send latest sensor reading to pi via wrapper
  void sendSensorLog();
  // Get reading interval from pi via wrapper
  // Updates: interval data member
  void getInterval();
  // Calculate resistance from analogReading
  // Updates: resistance data member
  void calcRes();
  // Calculates temperature from resistance
  // Updates: temp data member
  void calcTemp();
};
```


### PiWrapper

[PiWrapper](https://github.com/olincollege/SoftSysHydro/blob/main/lib/PiWrapper/PiWrapper.h) is a class that each sensor or actuator inherits from. PiWrapper standardizes the way that messages to the Pi are sent and received. The original implementation is shown below:

```c++
class PiWrapper {
    public:
    String port = "/dev/ttyACM0";
    String systemId = "system/1";
    // Send data to the pi
    static String sendData(double data, String type);
    // Send data to the pi
    static String sendData(String data, String type);
    // Get data from the pi
    static String getData(String request, String type);
};
```
This original implementation worked, however it required overloading and was difficult to unit test. Additionally, it was written to accomodate sensors and was not generalized to work with actuators. The code was refactored to the following:

```c++
class PiWrapper
{
public:
    String sep = ":";
    String query = "";
    typedef struct
    {
        String dataType;
        String reqType;
        String sensorName;
        String data;
    } Query;
    Query q;
    uint64_t timeout = 20000;
    // Create and send a query to the pi
    void sendQuery();
    // Create the payload to be sent based on q and update query
    void createQuery();
    // Wait for and get response after sending a request
    String getResponse();
    // Determines if timeout has occured
    bool hasTimedOut(uint64_t startTime);
};
```
The Query struct was created to standardize the format of data needed to send a message. This struct acted as a reference for what data each module that inherits from it needs to contain. To send a message, you can update q with your data then call sendQuery. The createQuery function was created to make unit testing more straightforward. This class went through one final change to reduce the amount of memory used:

```c++
class PiWrapper
{
public:
    String sep = ":";
    String query = "";
    typedef struct
    {
        String dataType;
        String reqType;
        String sensorName;
        String data;
    } Query;
    uint64_t timeout = 20000;
    // Send a query to the pi
    void sendQuery();
    // Create the payload to be sent based on q and update query
    void createQuery(Query q);
    // Wait for and get response after sending a request
    String getResponse();
    // Determines if timeout has occured
    bool hasTimedOut(uint64_t startTime);
};
```
There is no reason to keep track of Query q after the query string is created. This means that memory is being wasted by keeping the variable in this class, rather than allowing it to get destroyed when the calling function's stack frame is discarded. Further, removing q makes it clear that the caller must provide all pieces of the Query struct, preventing unintended reuse from previous calls.

## Unit Testing

To unit test the firmware I used platformio's built in unit testing framework. Each class has its own test folder and set of tests. To run the test you can simply type ```pio test``` when in the main directory while connected to an Arduino mega2560. This will upload the testing groups one by one to the Arduino and run the tests, then report back the results. Below is the summary output from the tests.

```bash
Test            Environment     Status    Duration
--------------  --------------  --------  ------------
testEcSensor    megaatmega2560  PASSED    00:00:13.358
testPhSensor    megaatmega2560  PASSED    00:00:12.545
testPiWrapper   megaatmega2560  PASSED    00:00:09.809
testRelay       megaatmega2560  PASSED    00:00:10.879
testTempSensor  megaatmega2560  PASSED    00:00:12.240

```
Below is a simplified test file for the temperature sensor. Each test is defined as a function with an assertion. The tests are then run one by one in the setup function. The full temperature sensor test file can be found [here](https://github.com/olincollege/SoftSysHydro/blob/main/test/testTempSensor/testMain.cpp). 
```c
#include <TempSensor.h>
#include <unity.h>

TempSensor tempSensor(A2);

void testGetReading()
{
  tempSensor.getReading();
  Serial.println(tempSensor.temp);
  TEST_ASSERT(tempSensor.temp > 10.0 && tempSensor.temp < 35.0);
}

void setup()
{
  UNITY_BEGIN();
  RUN_TEST(testGetReading);
  UNITY_END();
}
```


## Reflection

I addressed my learning goals well in this project. I feel much more comfortable with c++ syntax and usage. I wrote the classes to be as general as possible to make them portable to new projects. I originally planned to remove my usage of the Arduino libraries, however instead I kept them and learned about how they are implemented and optimized for Arduinos. I explored some memory management in PiWrapper, but did not consider it as much as I had hoped. This program does not depend on speed or have any major memory limitations while running, which made it difficult to prioritize. I acccomplished a middle bound in this project. I was able to get all the lower bound items as well as the relay outlet controls. When I had finished these main items, my focus shifted to testing and calibrating. This project can successfully run in our pipeline for over 24 hours without interruption. It can take pH, temperature, and conductivity readings, as well as adjust the pH, and nutrient levels using pumps.
