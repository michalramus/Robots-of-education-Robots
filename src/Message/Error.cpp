#include "Message/Error.hpp"

#include "stdint.h"

void Error::setError(uint16_t errorType, char *errorMessage) //set error object
{
    this->errorType = errorType;
    this->errorMessage = errorMessage;
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

bool Error::isConfigured()
{
    return this->configured;
}
