#include "Message/VMsgContainer.hpp"

#ifndef NATIVE
#include <stdint.h>
#else
#include <ArduinoFake.h>
#endif

#pragma once

class Task : public VMsgContainer
{
public:
    ~Task();

    //getter and setter of task
    int16_t getTask();
    void setTask(int16_t task);

    //getter and setter of extraValue
    int16_t getExtraValue(int16_t valueID);
    void setExtraValue(int16_t valueID, int16_t value); //important to set extraValuesSize first

    //getter and setter of extraValuesSize
    int8_t getExtraValuesSize();
    void setExtraValuesSize(int8_t size);

private:
    //variables
    int16_t task = -1;

    //extra values
    int16_t **extraValues = nullptr; //table with extra values [valueID][value]
    int8_t extraValuesSize = -1;
    int8_t freeExtraValue = 0; //last free index of extraValues array
};
