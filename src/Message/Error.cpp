#include "Message/Error.hpp"

#ifndef NATIVE
#include <stdlib.h>
#else
#include <ArduinoFake.h>
#endif

//set error object
void Error::setError(uint16_t errorType, const char errorMessage[])
{
    char empty[] = "";
    setError(errorType, errorMessage, empty);
}

void Error::setError(uint16_t errorType, const char errorMessage[], int32_t errorValue)
{
    char buf[10];              //stores converted errorValue
    itoa(errorValue, buf, 10); //convert errorValue to string

    setError(errorType, errorMessage, buf);
}

void Error::setError(uint16_t errorType, const char errorMessage[], char *errorValue)
{
    this->errorType = errorType;
    this->errorMessage = (char *)errorMessage;
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
