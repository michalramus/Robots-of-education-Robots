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

            if (((String)message[0] == CommSymbol::getSymbol(CommSymbolID::startEndMessage)) && ((String)message[sizeof(message) / sizeof(message[0]) - 1] == CommSymbol::getSymbol(CommSymbolID::startEndMessage))) //check if message transfer is completed
            {
                messageReceived = true;
            }
        }
    }
        //TODO delete first and last character in message variable
    return message;
}
