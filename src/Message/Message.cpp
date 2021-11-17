
#include "Symbols/Symbols.hpp"
#include "Message/Message.hpp"
#include "Message/Device.hpp"

#include <ArduinoJson.h>

//TODO: update jsonDocument
//TODO: check if config message was sended more than 2 times
Message::~Message() //destructor
{
    if (devTypes != nullptr) //delete devTypes array if exist
    {
        for (int8_t i = 0; i < devTypesLength; i++)
        {
            delete devTypes[i];
            devTypes[i] = nullptr;
        }

        delete devTypes;
        devTypes = nullptr;
    }
}

void Message::setMessageByJson(char *message) //add convert Json message to Message object !!!METHOD DELETE MESSAGE VARIABLE!!!
{
    //TODO: different JsonBufferSize after config
    //create JsonDocument
    StaticJsonDocument<JSON_BUFFER_SIZE> doc;
    Message::deserializeMessage(message, doc);

    delete[] message;

    messageType = getMessageTypeID(doc); //set message type

    switch (messageType) //check message type
    {
    case SymbolsIDs::msgTypeError:
        /* code */
        break;
    case SymbolsIDs::msgTypeConfig:
        setupConfigMsg(doc);
        break;
    case SymbolsIDs::msgTypeInfo:
        /* code */
        break;
    case SymbolsIDs::msgTypeTask:
        /* code */
        break;
    }
}

char *Message::getCharMessage() //get message converted to char array
{
    //TODO: remember to set charMessageLength variable
}

int16_t Message::getCharMessageLength() //get length of char array with message after serialization
{
    if (charMessageLength != -1)
    {
        return charMessageLength;
    }
    else
    {
        //TODO: throw exception
    }
}

int8_t Message::getDevTypesLength() //CONFIG get length of array with device types
{
    if (Message::devTypesLength != -1)
    {
        return Message::devTypesLength;
    }
    else
    {
        //TODO: throw exception
    }
}

void Message::deserializeMessage(char *message, JsonDocument &doc) //deserialize message to JsonDocument
{
    DeserializationError error = deserializeJson(doc, message); //deserialize message

    if (error == true) //check if deserialization was successful
    {
        //TODO: throw exception(send an error)
    }
}

int16_t Message::getMessageTypeID(JsonDocument &doc) //get ID of message type
{
    String type = doc[SymbolsBase::getSymbol(SymbolsIDs::messageType)]; 

    return SymbolsBase::getID(type, SymbolsIDs::messageType); 
}

void Message::setupConfigMsg(JsonDocument &doc) //setup Message as config
{
    devTypesLength = doc[SymbolsBase::getSymbol(SymbolsIDs::msgConfDeviceTypes)].size(); //get length of device types array

    //create array of device types
    *devTypes = new uint16_t[devTypesLength];

    for (int16_t i = 0; i < devTypesLength; i++)
    {
        devTypes[i] = new uint16_t[2];
    }


    for (int16_t i = 0; i < devTypesLength; i++) //write available devices' IDs to devTypes array
    {
        devTypes[i][0] = SymbolsBase::getID(doc[SymbolsBase::getSymbol(SymbolsIDs::msgConfDeviceTypes)][i]); //write device ID
        devTypes[i][1] = doc[SymbolsBase::getSymbol(devTypes[i][0])]; //write number of devices
    }


    Dev = new Device[devTypesLength]; //create array of devices
    
    uint8_t freeDevPtr = 0; //pointer to free device in array of devices

    for (uint8_t i = 0; i < devTypesLength; i++)// set Devices
    {
        uint16_t devType = devTypes[i][0]; 
        
        for (uint8_t j = 0; j < devTypes[i][1]; j++)
        {
            //BUG: test this line and optimize
            Dev[freeDevPtr].setDevType(doc[SymbolsBase::getSymbol(devType) + i][SymbolsBase::getSymbol(SymbolsIDs::deviceID)]); //set ID
            Dev[freeDevPtr].setDevType(devType); //set Type

            uint8_t pinsLength = doc[SymbolsBase::getSymbol(devType) + i][SymbolsBase::getSymbol(SymbolsIDs::pinsArray)].size(); //get size of pins array
            uint8_t pins[pinsLength];

            for (uint8_t k = 0; k < pinsLength; k++) //set pins array
            {
                pins[k] = doc[SymbolsBase::getSymbol(devType) + i][SymbolsBase::getSymbol(SymbolsIDs::pinsArray)][k];
            }

            Dev[freeDevPtr].setPins(pins); //set pins array in Device
            freeDevPtr++;
        }
    }
}
