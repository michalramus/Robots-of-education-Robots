#include <Arduino.h>

#pragma once
class SerialCommunication
{
public:
    void setBaudRate(int baudRate);

private:
    String readValues(); //read values from Serial
};
