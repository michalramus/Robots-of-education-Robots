#include "Message/VMsgContainer.hpp"

#include <stdint.h>

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
        //TODO: throw exception
    }
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
        //TODO: throw exception
    }
}
