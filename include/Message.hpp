#include <WString.h>
#include <ArduinoJson.h>

#pragma once

class Message
{
public:
    ~Message(); //destructor

    void setJsonMessage(String message); //add convert Json message to Message object

private:
    void deserializeMessage(String message, JsonDocument &doc); //deserialize message to JsonDocument

    int getMessageTypeID(JsonDocument &doc); //get message type ID

    void setupConfigMsg(JsonDocument &doc); //setup message as config

     const static int JSON_BUFFER_SIZE = 30; //TODO: set buffer size

    int messageType = NULL;

        //config
    //car
    int* devTypes;
    int numOfCar = NULL;
};


