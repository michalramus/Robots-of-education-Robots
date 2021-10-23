#include <ArduinoJson.h>
#include "Symbols/Symbols.hpp"

#include "Message.hpp"

//TODO: update jsonDocument
//TODO: check if config message was sended more than 2 times
Message::~Message() //destructor
{
    delete[] devTypes;
}

void Message::setJsonMessage(String message) //add convert Json message to Message object
{
    //create JsonDocument
    StaticJsonDocument<JSON_BUFFER_SIZE> doc;
    Message::deserializeMessage(message, doc);

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

void Message::deserializeMessage(String message, JsonDocument &doc) //deserialize message to JsonDocument
{
    DeserializationError error = deserializeJson(doc, message); //deserialize message

    if (error == true) //check if deserialization is successfull 
    {
        //TODO: throw exception(send an error)
    }
}

uint16_t Message::getMessageTypeID(JsonDocument &doc) //get ID of message type
{
    String type = doc[SymbolsBase::getSymbol(SymbolsIDs::messageType)]; //get type of message

    return SymbolsBase::getID(type, SymbolsIDs::messageType); //set messageType variable to ID of symbol
}

void Message::setupConfigMsg(JsonDocument &doc)
{

}
