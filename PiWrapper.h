class PiWrapper {
    public:
    // Send data to the pi
    char sendData(int data, char type);
    char sendData(char data, char type);
    // Get data from the pi
    char getData(char request);
};