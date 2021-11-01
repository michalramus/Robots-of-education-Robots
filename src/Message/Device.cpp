#include "Message/Device.hpp"


Device::~Device() //destructor
{
    if (pins == nullptr) //delete pins table
    {
        delete[] pins;
        pins = nullptr;
    }
}

//getter and setter of devType variable
void Device::setDevType(uint16_t devType)
{
    this->devType = devType;
}

uint16_t Device::getDevType()
{
    return devType;
}


//getter and setter of ID variable
void Device::setID(uint8_t ID)
{
    this->ID = ID;
}

uint8_t Device::getID()
{
    return ID;
}


//getter and setter of table with pins
void Device::setPins(uint8_t *pins)
{
    this->pins = pins;
}

uint8_t *Device::getPinsPtr()
{
    return pins;
}
