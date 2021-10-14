#include <Arduino.h>

#pragma once
class SerialCommunication
{
public:
    static void setBaudRate(int baudRate);
    static String readValues(); //read values from Serial

private:
    
};
