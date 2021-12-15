#include "Interfaces/IMessage.hpp"
#include "Message/Error.hpp"

#ifndef NATIVE
#include <stdint.h>
#else
#include <ArduinoFake.h>
#endif

#pragma once

class Exceptions
{
public:
    static void throwException(Error error);
    static void setCommunication(IMessage *message, void (*sendMessage)(IMessage&)); //set communication interface and message class
private:
    static void freezeController(); //start infinite loop

    //variables

    static void (*_sendMessage)(IMessage&); //communication interface
    static IMessage *_message; //message to send

    static bool exceptionCalled; //stores if exception was thrown
};

#include "Exceptions/ExceptionsBase.hpp"
