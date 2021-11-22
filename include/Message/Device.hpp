#include <Message/VMsgContainer.hpp>

#include <stdint.h>

#pragma once

class Device : public VMsgContainer
{
public:
    ~Device();

    //getter and setter of table with pins
    void setPins(uint8_t *pins); //!!METHOD DELETE TABLE DURING DESTRUCTION!!
    uint8_t *getPinsPtr();


private:
    uint8_t *pins = nullptr; //table with pins
};
