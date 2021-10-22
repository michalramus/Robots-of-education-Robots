#include <ArduinoJson.h>
#include "CommunicationRules.hpp"

#include "Message.hpp"

//TODO: update jsonDocument

Message::~Message() //destructor
{
    delete devTypes;
}

void Message::setJsonMessage(String message) //add convert Json message to Message object
{
    //create JsonDocument
    StaticJsonDocument<JSON_BUFFER_SIZE> doc;
    Message::deserializeMessage(message, doc);

    messageType = getMessageTypeID(doc); //set message type

    switch (messageType) //check message type
    {
    case CommSymbolID::msgTypeError:
        /* code */
        break;
    case CommSymbolID::msgTypeConfig:
        setupConfigMsg(doc);
        break;
    case CommSymbolID::msgTypeInfo:
        /* code */
        break;
    case CommSymbolID::msgTypeTask:
        /* code */
        break;
    }
}

void Message::deserializeMessage(String message, JsonDocument &doc) //deserialize message to JsonDocument
{
    DeserializationError error = deserializeJson(doc, message); //deserialize message

    if (error == true) //check if deserialization is successfull 
    {
        //TODO: throw exception
    }
}

int Message::getMessageTypeID(JsonDocument &doc) //get ID of message type
{
    String type = doc[CommSymbol::getSymbol(CommSymbolID::messageType)]; //get type of message

    return CommSymbol::getID(type, CommSymbolID::messageType); //set messageType variable to ID of symbol
}

void Message::setupConfigMsg(JsonDocument &doc)
{

}
