#include <stdint.h>

#pragma once

class Error
{
public:
    void setError(uint16_t errorType, char *errorMessage); //set error object

    //getters of error object
    uint16_t getErrorType();
    char *getErrorMessage();

    bool isConfigured(); //is error msg configured

private:
    uint16_t errorType = -1;
    char *errorMessage = nullptr;

    bool configured = false; //is error object configured
};
