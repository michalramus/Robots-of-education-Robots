#include "Message/Error.hpp"

#include "stdint.h"

void Error::setError(uint16_t errorType, char *errorMessage) //set error object
{
    setError(errorType, errorMessage, "");
}

void Error::setError(uint16_t errorType, char *errorMessage, char *errorValue) //set error object
{
    this->errorType = errorType;
    this->errorMessage = errorMessage;
    this->errorValue = errorValue;
    configured = true;
}

uint16_t Error::getErrorType() //get error type
{
    return this->errorType;
}

char *Error::getErrorMessage() //get error message
{
    return this->errorMessage;
}

char *Error::getErrorValue() //get error value
{
    return this->errorValue;
}

bool Error::isConfigured()
{
    return this->configured;
}
