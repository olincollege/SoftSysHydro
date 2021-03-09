# circadia

## Compiling:
Using g++ you can run the following to compile and create a main.exe file:
```
g++ -c main.cpp PhSensor.cpp PiWrapper.cpp 
g++ -o main.exe main.o PhSensor.o PiWrapper.o
```
Run the main file:
```
./main.exe
```

Open Questions:
- How to prevent coupling between arduino -> pi -> data api. i.e. If the arduino needs the ph range, it will need to make a request through the pi, the pi will interpret this and then send a request to the data api. How can we minimize the number of changes needed to make if one of these pieces along the chain changes?