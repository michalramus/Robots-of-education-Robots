#include "Message/Task.hpp"
#include "Message/Error.hpp"

#ifndef NATIVE
#include <stdint.h>
#else
#include <ArduinoFake.h>
#endif

Task::~Task()
{
    //delete extraValues array
    if (extraValues != nullptr)
    {
        for (int8_t i = 0; i < extraValuesSize; i++)
        {
            delete[] extraValues[i];
        }

        delete[] extraValues;
        extraValues = nullptr;
    }
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
        //create error
        Error error;

        //throw exception
        error.setError(ExceptionsBase::nonSetValue, "Trying to get task value in Task");
        _throwException(error);
    }

    return 0; //it is not possible to reach this line
}

void Task::setTask(int16_t task)
{
    this->task = task;
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

        //create error
        Error error;

        //throw exception
        error.setError(ExceptionsBase::nonSetValue, "Trying to get extraValue: value not found", valueID);
        _throwException(error);
    }
    else
    {
        //create error
        Error error;

        //throw exception
        error.setError(ExceptionsBase::nonSetValue, "Trying to get extraValue value in Task: extraValues non set", valueID);
        _throwException(error);
    }

    return 0; //it is not possible to reach this line
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
        //create error
        Error error;

        //throw exception
        error.setError(ExceptionsBase::nonSetValue, "Trying to get extraValuesSize value in Task");
        _throwException(error);
    }

    return 0; //it is not possible to reach this line
}

void Task::setExtraValuesSize(int8_t size)
{
    this->extraValuesSize = size;
}
