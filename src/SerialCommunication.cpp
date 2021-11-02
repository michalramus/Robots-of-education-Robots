#include "Symbols/Symbols.hpp"
#include "SerialCommunication.hpp"
#include "Exceptions.hpp"
#include "Message/Message.hpp"

#include <ArduinoJson.h>
#include <Arduino.h> 

//TODO: add default value
void SerialCommunication::setBaudRate(uint16_t baudRate)
{
    Serial.begin(baudRate); //Start Serial
}

Message &SerialCommunication::readMessage() //read values from Serial
{
    const uint16_t WAITING_TIME = 2000; //time after that message will be considered as invalid
    bool timerStarted = false;          //check if timer start
    unsigned long int timer = 0;        //time since last message character was received

    bool messageReceived = false;           //was message completely received
    //TODO: different size after config
    char bigMessage[SERIAL_RX_BUFFER_SIZE]; //char table (max message size)
    uint16_t bigMessagePtr = 0;             //first free place in bigMessage variable

    while (messageReceived == false) //waiting for message
    {

        while (Serial.available() > 0) //receive message
        {
            timerStarted = true; //start timer
            timer = millis();    // set timer to actual time

            bigMessage[bigMessagePtr] = Serial.read();
            bigMessagePtr++; //increase last free place
        }

        if (bigMessagePtr > 1) //check if received message has more than 1 character
        {
            if ((bigMessage[0] == (char)SymbolsBase::getSymbol(SymbolsIDs::startEndMessage)[0]) && (bigMessage[bigMessagePtr - 1] == (char)SymbolsBase::getSymbol(SymbolsIDs::startEndMessage)[0])) //check if message transfer is completed
            {
                messageReceived = true;
            }
        }

        if ((true == timerStarted) && (timer + WAITING_TIME < millis())) //check if last message's character was received longer than 2 seconds
        {
            //TODO: add exception
        }
    }

    //rewrite message to smaller table and remove "x" character from start and end of message
    char smallMessage[bigMessagePtr - (1 + (2 * SymbolsBase::getSymbol(SymbolsIDs::startEndMessage).length()))]; // Table with the same size like message
    uint16_t smallMessagePtr = 0;                                                                                //first free place in smallMessage variable

    //rewrite message to smaller table
    for (uint16_t i = SymbolsBase::getSymbol(SymbolsIDs::startEndMessage).length(); i < bigMessagePtr - SymbolsBase::getSymbol(SymbolsIDs::startEndMessage).length(); i++)
    {
        smallMessage[smallMessagePtr] = bigMessage[i];

        smallMessagePtr++; //increase free place
    }

    //TODO: don't delete bigMessage move it into class body and clean after use
    delete[] bigMessage; //delete first table with message

    Message Msg;                      //create message object
    Msg.setMessageByJson(smallMessage); //set message from Json

    return Msg;
}

void SerialCommunication::sendMessage(Message message) //send message
{
    char *MsgToSend = message.getCharMessage(); //get message converted to char array
    
    sendMessage(MsgToSend, message.getCharMessageLength()); //send message
}

void SerialCommunication::sendSpecifiedMessage(int16_t type) //send message, that last message was received
{
    //TODO:
}

void SerialCommunication::sendMessage(char *message, uint16_t messageLength) //send message
{
    char messageWithStrEndMsgChar[messageLength + (2 * SymbolsBase::getSymbol(SymbolsIDs::startEndMessage).length())]; //create char table with size that includentartEndMessage character
    uint16_t ptrMessage = 0;                                                                                           //pointer, that is set for the first free element in table

    uint8_t startEndMessageLength = SymbolsBase::getSymbol(SymbolsIDs::startEndMessage).length(); //get length of startEndMessage symbol

    for (uint16_t i = 0; i < startEndMessageLength; i++) //add startEndMessage symbol at the begin of MessageWithStrMsgChar
    {
        messageWithStrEndMsgChar[ptrMessage] = SymbolsBase::getSymbol(SymbolsIDs::startEndMessage)[i];
        ptrMessage++;
    }

    for (size_t i = 0; i < messageLength; i++) //rewrite message to messageWithEndMshChar
    {
        messageWithStrEndMsgChar[ptrMessage] = message[i];
        ptrMessage++;
    }

    for (uint16_t i = 0; i < startEndMessageLength; i++) //add startEndMessage symbol at the end of MessageWithStrMsgChar
    {
        messageWithStrEndMsgChar[ptrMessage] = SymbolsBase::getSymbol(SymbolsIDs::startEndMessage)[i];
        ptrMessage++;
    }

    Serial.println(messageWithStrEndMsgChar); //send message
    
}

