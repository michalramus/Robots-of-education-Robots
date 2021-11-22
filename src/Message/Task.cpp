#include "Message/Task.hpp"

#include <stdint.h>

Task::~Task()
{
    //delete extraValues array
    if (extraValues != nullptr)
    {
        for (int8_t i = 0; i < extraValuesSize; i++)
        {
            delete extraValues[i];
        }
        
        delete extraValues;
        extraValues = nullptr;
    }
}

//getter and setter of device type
int16_t Task::getDevType()
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

void Task::setDevType(int16_t devType)
{
    this->devType = devType;
}

//getter and setter of ID
int8_t Task::getID()
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

void Task::setID(int8_t)
{
    this->ID = ID;
}

//getter and setter of task
int16_t Task::getTask()
{
    if (task != -1)
    {
        return task;
    }
    else
    {
        //TODO: throw exception
    }
}

//getter and setter of extraValue
int16_t Task::getExtraValue(int16_t valueID)
{
    if (extraValues != nullptr)
    {
        for (int8_t i = 0; i < extraValuesSize; i++) //find value ID
        {
            if (extraValues[i][0] == valueID)
            {
                return extraValues[i][0];
            }
        }
        //value ID not found
        //TODO: throw exception
    }
    else
    {
        //TODO: throw exception
    }
}

void Task::setExtraValue(int16_t valueID, int16_t value)
{
    if ((extraValues = nullptr) && (extraValuesSize != -1))
    {
        //create extraValues array
        extraValues = new int16_t *[extraValuesSize];

        for (int8_t i = 0; i < extraValuesSize; i++)
        {
            extraValues[i] = new int16_t[2];
        }
    }

    //set values
    extraValues[freeExtraValue][0] = valueID;
    extraValues[freeExtraValue][1] = value;

    freeExtraValue++;
}

//getter and setter of extraValuesSize
int8_t Task::getExtraValuesSize()
{
    if (extraValuesSize != -1)
    {
        return extraValuesSize;
    }
    else
    {
        //TODO: throw exception
    }
}

void Task::setExtraValuesSize(int8_t size)
{
    this->extraValuesSize = size;
}
