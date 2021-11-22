#include <stdint.h>

#pragma once

class IMessage
{
public:
    virtual ~IMessage() = default;
    
    virtual void setMessageByJson(char *message);
    
    virtual char *getCharMessage();
    virtual int16_t getCharMessageLength();
    
    //config
    virtual int8_t getDevTypesLength();
};
