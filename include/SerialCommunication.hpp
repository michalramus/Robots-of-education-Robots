#include <Arduino.h>
class SerialCommunication
{
public:
    SerialCommunication(const int BaudRate); //constructor
    ~SerialCommunication();                  //destructor

    int getValues(); //get information from communication


private:
    String readValues(); //read values from Serial
};
