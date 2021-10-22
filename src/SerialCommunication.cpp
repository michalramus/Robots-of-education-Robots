#include <Arduino.h>
#include "CommunicationRules.hpp"
#include "SerialCommunication.hpp"
#include "Exceptions.hpp"
//TODO: add default value
void SerialCommunication::setBaudRate(uint16_t baudRate)
{
    Serial.begin(baudRate); //Start Serial
}

String SerialCommunication::readMessage() //read values from Serial
{
    const uint16_t WAITING_TIME = 2000; //time after that message will be considered as invalid
    bool timerStarted = false; //check if timer start
    unsigned long int timer = 0; //time since last message character was received
    
    bool messageReceived = false; //was message completely received
    String message = "";          //message from Serial

    while (messageReceived == false) //waiting for message
    {
        if (Serial.available() == true)
        {
            timerStarted = true;//start timer 
            timer = millis(); // set timer to actual time

            message += Serial.readString();

            if (((String)message[0] == CommSymbol::getSymbol(CommSymbolID::startEndMessage)) && ((String)message[message.length() - 1] == CommSymbol::getSymbol(CommSymbolID::startEndMessage))) //check if message transfer is completed
            {
                messageReceived = true;
                
            }
        }

        if ((true == timerStarted) && (timer + WAITING_TIME < millis())) //check if last message's character was received longer than 2 seconds
        {
            Exceptions::addReceivedMessage(message);
            //TODO: add exception
        }
    }

    Exceptions::addReceivedMessage(message); //add message to messages' index

    //remove "x" character from start and end of message
    message.remove(0);
    message.remove(message.length() - 1);

    SerialCommunication::lastReceivedMessage = message;
    return message;
}

void SerialCommunication::sendMessage(String message)//send message
{
    message = CommSymbol::getSymbol(CommSymbolID::startEndMessage) + message + CommSymbol::getSymbol(CommSymbolID::startEndMessage); //add startEndMessage symbol at start and end of message

    Exceptions::addSendedMessage(message); //add message to messages' index
    Serial.println(message);
    
}

void SerialCommunication::sendLastMessage() //send last message
{
    SerialCommunication::sendMessage(lastReceivedMessage);
}

void SerialCommunication::sendMessageReceived() //send message, that last message was received
{
    //TODO:
}
