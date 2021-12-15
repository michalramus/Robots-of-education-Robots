#include "Message/Error.hpp"
#include "Exceptions/Exceptions.hpp"

#ifndef NATIVE
#include <stdint.h>
#else
#include <ArduinoFake.h>
#endif

#pragma once

class VMsgContainer
{
public:
    //getter and setter of devType variable
    virtual void setDevType(int16_t devType);
    virtual int16_t getDevType();

    //getter and setter of ID variable
    virtual void setID(int8_t ID);
    virtual int8_t getID();

protected:
    int16_t devType = -1; //type of device
    int8_t ID = -1;       //ID of device

    void (*_throwException)(Error error) = &Exceptions::throwException; //method for throwing exception
};
