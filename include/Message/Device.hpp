#include <stdint.h>
#include <Arduino.h>

#pragma once

class Device
{
public:
   ~Device();

private:
    uint16_t devType = -1; //type of device
    uint8_t ID = -1; //ID of device

    uint8_t *pins = nullptr; //table with pins
    uint16_t *values[2]; //table with extra values to set 
    //TODO: change to dictionary values table

};
