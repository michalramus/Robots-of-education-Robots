#include "Interfaces/IMessage.hpp"

#include <WString.h>

#pragma once
class SerialCommunication
{
public:
    static void setBaudRate(uint16_t baudRate);

    static IMessage readMessage(IMessage messageClass); //receive message from Serial
    
    static void sendMessage(IMessage message); //send message
    static void sendSpecifiedMessage(int16_t type); //send message, that last message was received


private:
    static void sendMessage(char *message, uint16_t messageLength); //send message
};
