#include <SerialCommunication.hpp>
#include <Arduino.h>
#include <CommunicationRules.hpp>

SerialCommunication::SerialCommunication(const int BaudRate) //constructor
{
    Serial.begin(BaudRate); //Start Serial
}

SerialCommunication::~SerialCommunication() //destructor
{
    //empty
}

String SerialCommunication::readValues() //read values from Serial
{
    bool messageReceived = false; //was message completely received
    String message = "";          //message from Serial

    while (messageReceived == false) //waiting for message
    {
        if (Serial.available() == true)
        {
            message += Serial.readString();

            if ((message[0] == CommChar::getChar(CommCharID::startEndMessage)) && (message[sizeof(message) / sizeof(message[0]) - 1] == CommChar::getChar(CommCharID::startEndMessage))) //check if message transfer is completed
            {
                messageReceived = true;
            }
        }
    }

    return message;
}
