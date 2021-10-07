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

String SerialCommunication::readValues() //read values from Serial
{
    bool messageReceived = false; //was message completely received
    String message = "";          //message from Serial

    while (messageReceived == false) //waiting for message
    {
        if (Serial.available() == true)
        {
            message += Serial.available();

            if ((message[0] == 'x') && (message[sizeof(message) / sizeof(message[0]) - 1] == 'x')) //check if message transfer is completed
            {
                messageReceived == true;
            }
        }
    }

    return message;
}
