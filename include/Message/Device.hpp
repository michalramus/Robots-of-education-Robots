#include <stdint.h>

#pragma once

class Device
{
public:
    ~Device();

    //getter and setter of devType variable
    void setDevType(int16_t devType);
    int16_t getDevType();

    //getter and setter of ID variable
    void setID(int8_t ID);
    int8_t getID();

    //getter and setter of table with pins
    void setPins(uint8_t *pins); //!!METHOD DELETE TABLE DURING DESTRUCTION!!
    uint8_t *getPinsPtr();


private:
    int16_t devType = -1; //type of device
    int8_t ID = -1; //ID of device

    uint8_t *pins = nullptr; //table with pins
};
