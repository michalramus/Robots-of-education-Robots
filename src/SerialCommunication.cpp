#include <SerialCommunication.hpp>
#include <Arduino.h>

SerialCommunication::SerialCommunication(const int BaudRate) //constructor
{
    Serial.begin(BaudRate); //Start Serial
}

SerialCommunication::~SerialCommunication() //destructor
{
    //empty
}

String SerialCommunication::readValues()
{
    
}
