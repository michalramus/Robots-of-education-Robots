#include <Arduino.h>
#include "CommunicationRules.hpp"
#include "SerialCommunication.hpp"

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

            if (((String)message[0] == CommSymbol::getSymbol(CommSymbolID::startEndMessage)) && ((String)message[message.length() - 1] == CommSymbol::getSymbol(CommSymbolID::startEndMessage))) //check if message transfer is completed
            {
                messageReceived = true;
            }
        }
    }
    //remove "x" character from start and end of message
    message.remove(0);
    message.remove(message.length() - 1);
    
    return message;
}
