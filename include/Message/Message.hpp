#include "Message/Device.hpp"
#include "Message/Task.hpp"
#include "Interfaces/IMessage.hpp"
#include "Message/Error.hpp"
#include "Exceptions/Exceptions.hpp"

#ifndef NATIVE
#include <WString.h>
#else
#include <ArduinoFake.h>
#endif

#include <ArduinoJson.h>

#pragma once

class Message : public IMessage
{
public:
    ~Message(); //destructor

    void setMessageByJson(char *message); //convert Json message to Message object !!!METHOD DELETE MESSAGE VARIABLE!!!
    void setMessageByError(Error &error); //set message by error container

    char *getCharMessage();         //get message converted to char array
    int16_t getCharMessageLength(); //get length of char array with message after serialization

    void setExceptionMethod(void (*throwException)(Error error)); //set method for throwing exception

    //config
    int8_t getDevTypesLength(); //MSG TYPE: CONFIG get length of array with device types

private:
    void deserializeMessage(char *message, JsonDocument &doc); //deserialize message to JsonDocument

    int16_t getMessageTypeID(JsonDocument &doc); //get message type ID

    void setupConfigMsg(JsonDocument &doc); //setup message as config
    void setupTaskMsg(JsonDocument &doc);   //setup message as task

    //variables
    void (*_throwException)(Error error) = &Exceptions::throwException; //method for throwing exception

    int16_t charMessageLength = -1; //variable that stores length of char array with message
    int16_t messageType = -1;

    //config
    uint16_t **devTypes = nullptr; //array with device types [device type ID][count]
    int8_t devTypesLength = -1;    //length of array with device types

    Device *Dev = nullptr; //array with devices

    //task
    int8_t taskLength = 0; //size of task array
    Task *tasks = nullptr; //array with tasks

    //error
    Error *error = nullptr;
};
