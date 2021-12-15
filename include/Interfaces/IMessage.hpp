#include "Message/Error.hpp"

#ifndef NATIVE
#include <stdint.h>
#else
#include <ArduinoFake.h>
#endif

#pragma once

class IMessage
{
public:
    virtual ~IMessage() {}

    virtual void setMessageByJson(char *message) = 0;
    virtual void setMessageByError(Error &error) = 0; //set message by error container

    virtual char *getCharMessage() = 0;
    virtual int16_t getCharMessageLength() = 0;

    //config
    virtual int8_t getDevTypesLength() = 0;
};
