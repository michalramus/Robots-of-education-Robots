#include "Message/Error.hpp"

#include <stdint.h>

#pragma once

class IMessage
{
public:
    virtual ~IMessage();
    
    virtual void setMessageByJson(char *message);
    virtual void setMessageByError(Error error); //set message by error container

    virtual char *getCharMessage();
    virtual int16_t getCharMessageLength();
    
    //config
    virtual int8_t getDevTypesLength();
};
