#include "Symbols/Symbols.hpp"
#include "SerialCommunication.hpp"
#include "Interfaces/IMessage.hpp"
#include "Exceptions/Exceptions.hpp"
#include "Message/Error.hpp"


#ifndef NATIVE
    #include <WString.h>
    #include <HardwareSerial.h>
    #include <Arduino.h> //TODO: change to library with millis()method
#else
    #include <ArduinoFake.h>
    #define HardwareSerial SerialFake
#endif

//creation of class-static variables
HardwareSerial *SerialCommunication::_serial = nullptr;
void (*SerialCommunication::_throwException)(Error error) = nullptr;


void SerialCommunication::confSerialCommunication(HardwareSerial *serial, uint16_t baudRate, void (*exceptionMethod)(Error error))
{
    //setup serial
    _serial = serial;
    _serial->begin(baudRate);

    //setup error method
    _throwException = exceptionMethod;
}

IMessage* SerialCommunication::readMessage(IMessage& messageClass) //read values from Serial
{
    if (!_throwException) //check if error method was set
    {
        _throwException = &Exceptions::throwException;
    }

    const uint16_t WAITING_TIME = 2000; //time after that message will be considered as invalid
    bool timerStarted = false;          //check if timer start
    unsigned long int timer = 0;        //time since last message character was received

    bool messageReceived = false; //was message completely received
    //TODO: different size after config
    char *bigMessage = new char[SERIAL_RX_BUFFER_SIZE]; //char table (max message size)
    uint16_t bigMessagePtr = 0;                         //first free place in bigMessage variable

    while (messageReceived == false) //waiting for message
    {

        //TODO: USE TIMER INTERRUPT INSTEAD MILLIS()
        while (_serial->available() > 0) //receive message
        {
            timerStarted = true; //start timer
            timer = millis();    // set timer to actual time

            bigMessage[bigMessagePtr] = _serial->read();
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
            //setup error
            Error error;
            error.setError(ExceptionsBase::incorrectMessage, "Received incomplete message", bigMessage);

            //throw exception
            _throwException(error);
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

    delete[] bigMessage; //delete first table with message

    messageClass.setMessageByJson(smallMessage); //set message from Json

    return &messageClass; //TODO: check return
}

void SerialCommunication::sendMessage(IMessage& message) //send message
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

    //TODO: test and replace _serial->println to _serial->write
    _serial->println(messageWithStrEndMsgChar); //send message
}
