#include "Symbols/Symbols.hpp"
#include "SerialCommunication.hpp"
#include "Exceptions.hpp"
#include "Message/Message.hpp"

#include <WString.h>
#include <HardwareSerial.h>
#include <Arduino.h> //TODO: change to library with millis()method

//TODO: add default value
void SerialCommunication::setBaudRate(uint16_t baudRate)
{
    Serial.begin(baudRate); //Start Serial
}

Message &SerialCommunication::readMessage() //read values from Serial
{
    delete[] SerialCommunication::lastReceivedMessage;  //delete last message
    SerialCommunication::lastReceivedMessage = nullptr; //set pointer to null

    const uint16_t WAITING_TIME = 2000; //time after that message will be considered as invalid
    bool timerStarted = false;          //check if timer start
    unsigned long int timer = 0;        //time since last message character was received

    bool messageReceived = false;           //was message completely received
    char bigMessage[SERIAL_RX_BUFFER_SIZE]; //char table (max message size)
    uint16_t bigMessagePtr = 0;             //first free place in bigMessage variable

    while (messageReceived == false) //waiting for message
    {

        if (Serial.available() > 0)
        {
            timerStarted = true; //start timer
            timer = millis();    // set timer to actual time

            bigMessage[bigMessagePtr] = Serial.read();
            bigMessagePtr++; //increase last free place

            if (bigMessagePtr > 1) //check if received message has more than 1 character
            {
                if ((bigMessage[0] == (char)SymbolsBase::getSymbol(SymbolsIDs::startEndMessage)[0]) && (bigMessage[bigMessagePtr - 1] == (char)SymbolsBase::getSymbol(SymbolsIDs::startEndMessage)[0])) //check if message transfer is completed
                {
                    messageReceived = true;
                }
            }
        }

        if ((true == timerStarted) && (timer + WAITING_TIME < millis())) //check if last message's character was received longer than 2 seconds
        {
            SerialCommunication::lastReceivedMessage = "Incorrect message";
            //TODO: add exception
        }
    }

    //rewrite message to smaller table and remove "x" character from start and end of message
    char smallMessage[bigMessagePtr - (1 + (2 * SymbolsBase::getSymbol(SymbolsIDs::startEndMessage).length()))]; // Table with the same size like message
    uint16_t smallMessagePtr = 0; //first free place in smallMessage variable

    //rewrite message to smaller table  
    for (uint16_t i = SymbolsBase::getSymbol(SymbolsIDs::startEndMessage).length(); i < bigMessagePtr - SymbolsBase::getSymbol(SymbolsIDs::startEndMessage).length(); i++)
    {
        smallMessage[smallMessagePtr] = bigMessage[i];

        smallMessagePtr++;//increase free place
    }
    
    delete[] bigMessage; //delete first table with message

    SerialCommunication::lastReceivedMessage = smallMessage;

    Message Msg; //create message object
    Msg.setJsonMessage(smallMessage); //set message from Json

    return Msg;
}

void SerialCommunication::sendMessage(char message[]) //send message
{
    message = SymbolsBase::getSymbol(SymbolsIDs::startEndMessage) + message + SymbolsBase::getSymbol(SymbolsIDs::startEndMessage); //add startEndMessage symbol at start and end of message

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
