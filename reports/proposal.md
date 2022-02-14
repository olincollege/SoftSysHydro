# Automated Hydroponics Garden
### Jonas Kazlauskas  
## Project Goal
The goal of this project is to autonomously monitor and control a hydroponics garden with an arduino. The lower bound is to make a program in c++ that integrates with a ph sensor, ec sensor, temperature sensor, and peristaltic pumps to control the system. The MVP will be done in an object oriented way and will include unit testing. A stretch goal will be to include relay outlet controls, a water level sensor, and a seperate standalone testing program.  This is a project that was started in PINT's hydroponics subteam. There is currently code that has the ph sensor and ec sensor integrated. These will need to be rewritten to reduce reliance on the arduino framework. The starting version of this code can be found [here.](https://github.com/Olin-Hydro/circadia/commit/e49ae3136cc66cc65726b6823d3c179ce57df0de)

## Learning

In this project I want to develop my C++ skills and learn how to write my own libraries. I also want to explore unit testing and using standard C++ libraries instead of the arduino framework. Further, I want to consider things like memory management and the compilation process in my development. 

I plan on using the following resources:
- https://www.cplusplus.com/reference/
- https://cdn.makezine.com/uploads/2014/03/make-avr-programming-chapter-two.pdf
- https://www.w3schools.com/cpp/default.asp  
- Headfirst C

My first steps are to:
- Replace my usage of arduino's String in our current implementation with char arrays. This is will be considered complete when all current unit tests are updated and pass. 
- Learn how to use structs through headfirst c and add structs into the current implementation. This will be complete when at least 1 struct is used to improve the existing code and tests are passing.
- Wire and test the temperature sensor. This will be complete when I can use the arduino to read the temperature.