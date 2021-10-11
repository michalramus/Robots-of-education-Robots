#include <Arduino.h>

#pragma once
class SerialCommunication
{
public:
    SerialCommunication(const int BaudRate); //constructor
    ~SerialCommunication();                  //destructor

    int getValues(); //get information from communication


private:
    String readValues(); //read values from Serial
};
