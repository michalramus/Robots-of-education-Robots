#include <Interfaces/IMessage.hpp>

#include <stdint.h>

#pragma once

class Exceptions
{
public:
    static void throwException(IMessage message);
    static void setCommunication(void (*sendMessage)(IMessage)); //set communication interface
private:
    static void freezeController(); //start infinite loop

    //variables

    static void (*_sendMessage)(IMessage); //communication interface

};
