
#include "Symbols/Symbols.hpp"
#include "Message/Message.hpp"
#include "Message/Device.hpp"
#include "Message/Task.hpp"
#include "Message/Error.hpp"
#include "Exceptions/Exceptions.hpp"

#include <ArduinoJson.h>

//TODO: update jsonDocument
//TODO: check if config message was sended more than 2 times
Message::~Message() //destructor
{
    if (devTypes != nullptr) //delete devTypes array if exists
    {
        for (int8_t i = 0; i < devTypesLength; i++)
        {
            delete[] devTypes[i];
            devTypes[i] = nullptr;
        }

        delete[] devTypes;
        devTypes = nullptr;
    }

    if (Dev != nullptr) //delete Dev array if exists
    {
        delete[] Dev;
        Dev = nullptr;
    }

    if (tasks != nullptr) //delete tasks array if exists
    {
        delete[] tasks;
        tasks = nullptr;
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
        //TODO: add setup error message
        break;
    case SymbolsIDs::msgTypeConfig:
        setupConfigMsg(doc);
        break;
    case SymbolsIDs::msgTypeInfo:
        //TODO: add setup for info message
        break;
    case SymbolsIDs::msgTypeTask:
        setupTaskMsg(doc);
        break;
    }

    doc.clear(); //clear JsonDocument buffer
}

void Message::setMessageByError(Error &error) //set message by error container
{
    if(error.isConfigured() == false) //check if error was configured
    {
        error.setError(ExceptionsBase::unknownError, "Unknown error");
    }

    messageType = SymbolsIDs::msgTypeError;
    this->error = &error;
}

char *Message::getCharMessage() //get message converted to char array
{
    //TODO: remember to set charMessageLength variable

}

int16_t Message::getCharMessageLength() //get length of char array with message after serialization FIRST CALL getCharMessage METHOD
{
    if (charMessageLength != -1)
    {
        return charMessageLength;
    }
    else
    {
        //create error
        Error error;

        //throw exception
        error.setError(ExceptionsBase::nonSetValue, "CharMessageLength is not set in Message - message not converted to char array: first call getCharMessage() method");
        _throwException(error);
    }
    
    return 0; //it is not possible to reach this line
}

void Message::setExceptionMethod(void (*throwException)(Error error)) //set method for throwing exception
{
    _throwException = throwException;
}


int8_t Message::getDevTypesLength() //CONFIG get length of array with device types
{
    if (Message::devTypesLength != -1)
    {
        return Message::devTypesLength;
    }
    else
    {
        //create error
        Error error;

        //throw exception
        error.setError(ExceptionsBase::nonSetValue, "DevTypesLength is not set in Message: give JSON to deserialization");
        _throwException(error);
    }

    return 0; //it is not possible to reach this line
}

void Message::deserializeMessage(char *message, JsonDocument &doc) //deserialize message to JsonDocument
{
    DeserializationError desError = deserializeJson(doc, message); //deserialize message

    if (desError == true) //check if deserialization was successful
    {
        //create error
        Error error;
        char errorText[] = "Deserialization error";
        char errorMessage[strlen(errorText) + strlen(desError.c_str()) + 2];

        //concatenate errorText and desError to errorMessage

        strcat(errorMessage, errorText);
        strcat(errorMessage, ": ");
        strcat(errorMessage, desError.c_str());

        //throw exception
        error.setError(ExceptionsBase::incorrectMessage, errorMessage, message);
        _throwException(error);
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

void Message::setupTaskMsg(JsonDocument &doc) //setup Message as task
{
    taskLength = doc[SymbolsBase::getSymbol(SymbolsIDs::msgTaskTaskNumber)]; //get length of tasks array
    tasks = new Task[taskLength]; //create array of tasks

    for (int i = 0; i < taskLength; i++) //set tasks
    {
        tasks[i].setDevType(doc[SymbolsBase::getSymbol(SymbolsIDs::msgTypeTask) + i][SymbolsBase::getSymbol(SymbolsIDs::msgTaskDeviceType)]); //set device type
        tasks[i].setID(doc[SymbolsBase::getSymbol(SymbolsIDs::msgTypeTask) + i][SymbolsBase::getSymbol(SymbolsIDs::deviceID)]); //set device ID
        tasks[i].setTask(doc[SymbolsBase::getSymbol(SymbolsIDs::msgTypeTask) + i][SymbolsBase::getSymbol(SymbolsIDs::msgTaskTaskType)]); //set Task

        //set extra values
        tasks[i].setExtraValuesSize(doc[SymbolsBase::getSymbol(SymbolsIDs::msgTypeTask) + i][SymbolsBase::getSymbol(SymbolsIDs::msgTaskExtraValNum)]); //set size of extra values array

        for (int j = 0; j < tasks[i].getExtraValuesSize(); j++) //set extra values
        {
            tasks[i].setExtraValue(doc[SymbolsBase::getSymbol(SymbolsIDs::msgTypeTask) + i][SymbolsBase::getSymbol(SymbolsIDs::msgTaskExtraVal) + j][0], doc[SymbolsBase::getSymbol(SymbolsIDs::msgTypeTask) + i][SymbolsBase::getSymbol(SymbolsIDs::msgTaskExtraVal) + j][1]); //set extra values
        }
    }
}
