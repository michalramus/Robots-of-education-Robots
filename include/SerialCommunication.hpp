#include <Arduino.h>

#pragma once
class SerialCommunication
{
public:
    void setBaudRate(int baudRate);

    int getValues(); //get information from communication


private:
    String readValues(); //read values from Serial
};
