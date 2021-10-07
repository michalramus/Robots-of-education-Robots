#include <Arduino.h>
class SerialCommunication
{
public:
    SerialCommunication(const int BaudRate); //constructor
    ~SerialCommunication();                  //destructor


private:
    String readValues(); //read values from Serial
};
