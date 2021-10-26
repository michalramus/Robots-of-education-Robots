#include <WString.h>
#include <ArduinoJson.h>

#pragma once

class Message
{
public:
    Message();
    ~Message(); //destructor

    void setJsonMessage(char *message); //add convert Json message to Message object

private:
    void deserializeMessage(char *message, JsonDocument &doc); //deserialize message to JsonDocument

    uint16_t getMessageTypeID(JsonDocument &doc); //get message type ID

    void setupConfigMsg(JsonDocument &doc); //setup message as config

    uint16_t messageType = -1;

        //config
        uint16_t *devTypes = nullptr;
    //car
    uint8_t numOfCar = -1;
};


