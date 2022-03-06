# Automated Hydroponics Garden

### Jonas Kazlauskas

## Project Goal

The goal of this project is to autonomously monitor and control a hydroponics garden with an arduino. The lower bound is to make a program in c++ that integrates with a ph sensor, ec sensor, temperature sensor, and peristaltic pumps to control the system. The MVP will be done in an object oriented way and will include unit testing. A stretch goal will be to include relay outlet controls, a water level sensor, and a seperate standalone testing program. This is a project that was started in PINT's hydroponics subteam. There is currently code that has the ph sensor and ec sensor integrated. These will likely need to be refactored. The starting version of this code can be found [here.](https://github.com/Olin-Hydro/circadia/commit/e49ae3136cc66cc65726b6823d3c179ce57df0de)

## Learning

In this project I want to develop my C++ skills and learn how to write my own libraries. I also want to explore unit testing and learn about how arduino libraries are implemented. Further, I want to consider things like memory management and the compilation process in my development.

I plan on using the following resources:

- https://www.cplusplus.com/reference/
- https://cdn.makezine.com/uploads/2014/03/make-avr-programming-chapter-two.pdf
- https://www.w3schools.com/cpp/default.asp
- Headfirst C

## Process

I have added a temperature sensor, an RTC clock module, and relay controls for the peristaltic pumps and outlet controls. I have also rewritten portions of the existing ec and ph classes. To implement these new sensors I created a new temperature class and relay class. The relay class was written to be generalized and to control the peristaltic pumps and outlets. I also updated the existing PiWrapper base class that handles writing data to serial to use a struct for structuring queries. At the moment, the code is theoretically complete for the simple MVP and setup for future development. 

## Current Tasks

- Test the full system. This requires connecting all of the sensors and running the system for a longer period of time and ensuring that it performs as expected. This will be considered complete when the system can run for 24 hours without errors
- Calibrate parameters. This involves setting up a testing resevoir of water, nutrient solution, and ph down solution, then connecting the pumps. Next, I can run the system and adjust the dispensing time until the system reaches an acceptable equilibrium. This will be complete when I have determined numbers for dilution of nutrient solution and amount of time that the pumps should be on.
- Increase unit or integration testing. This is the least defined task, and will likely become more clear as I learn what common failure modes are. I want to create a way to test the system and simulate a longer period of time. This may require writing a separate piece of code. This will be complete when I have the ability to test the system's serial output.

## Links
[Task manager](https://todoist.com/app/project/2285722358)  
[Code repository](https://github.com/olincollege/SoftSysHydro)

