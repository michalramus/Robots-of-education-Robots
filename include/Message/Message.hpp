#include <WString.h>
#include <ArduinoJson.h>

#pragma once

class Message
{
public:
    Message();
    ~Message(); //destructor

    void setMessageByJson(char *message); //add convert Json message to Message object !!!METHOD DELETE MESSAGE VARIABLE!!!

private:
    void deserializeMessage(char *message, JsonDocument &doc); //deserialize message to JsonDocument

    int16_t getMessageTypeID(JsonDocument &doc); //get message type ID

    void setupConfigMsg(JsonDocument &doc); //setup message as config

    //variables
    int16_t messageType = -1;

        //config
        uint16_t *devTypes = nullptr;
    //car
    int8_t numOfCar = -1;
};


