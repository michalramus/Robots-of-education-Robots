#include "Message/VMsgContainer.hpp"
#include "Message/Error.hpp"

#ifndef NATIVE
#include <stdint.h>
#else
#include <ArduinoFake.h>
#endif

//getter and setter of devType variable
void VMsgContainer::setDevType(int16_t devType)
{
    this->devType = devType;
}

int16_t VMsgContainer::getDevType()
{
    if (devType != -1)
    {
        return devType;
    }
    else
    {
        //create error
        Error error;

        //throw exception
        error.setError(ExceptionsBase::nonSetValue, "Trying to get DevType value in VMsgContainer");
        _throwException(error);
    }

    return 0; //it is not possible to reach this line
}

//getter and setter of ID variable
void VMsgContainer::setID(int8_t ID)
{
    this->ID = ID;
}

int8_t VMsgContainer::getID()
{
    if (ID != -1)
    {
        return ID;
    }
    else
    {
        //create error
        Error error;

        //throw exception
        error.setError(ExceptionsBase::nonSetValue, "Trying to get ID value in VMsgContainer");
        _throwException(error);
    }

    return 0; //it is not possible to reach this line
}
