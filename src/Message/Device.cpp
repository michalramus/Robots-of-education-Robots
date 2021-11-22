#include "Message/Device.hpp"

Device::~Device() //destructor
{
    if (pins != nullptr) //delete pins table
    {
        delete[] pins;
        pins = nullptr;
    }
}

//getter and setter of table with pins
void Device::setPins(uint8_t *pins)
{
    this->pins = pins;
}

uint8_t *Device::getPinsPtr()
{
    if (pins != nullptr)
    {
        return pins;
    }
    else
    {
        //TODO: throw exception
    }
}
