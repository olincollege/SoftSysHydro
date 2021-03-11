#include <string>
using std::string;

class PiWrapper {
    public:
    // Send data to the pi
    static void sendData(int data, string type);
    // Send data to the pi
    static void sendData(string data, string type);
    // Get data from the pi
    static string getData(string request);
};