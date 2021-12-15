#ifndef NATIVE
#include <stdint.h>
#else
#include <ArduinoFake.h>
#endif

#pragma once

class Error
{
public:
    //set error object
    void setError(uint16_t errorType, const char errorMessage[]);
    void setError(uint16_t errorType, const char errorMessage[], int32_t errorValue);
    void setError(uint16_t errorType, const char errorMessage[], char *errorValue);

    //getters of error object
    uint16_t getErrorType();
    char *getErrorMessage();
    char *getErrorValue();

    bool isConfigured(); //is error msg configured

private:
    uint16_t errorType = -1;
    char *errorMessage = nullptr;
    char *errorValue = nullptr; //data that caused error

    bool configured = false; //is error object configured
};
