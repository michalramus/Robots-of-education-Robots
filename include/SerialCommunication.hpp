#include "Message/Message.hpp"

#include <WString.h>

#pragma once
class SerialCommunication
{
public:
    static void setBaudRate(uint16_t baudRate);

    static Message &readMessage(); //read values from Serial
    
    static void sendMessage(Message message); //send message
    static void sendSpecifiedMessage(int16_t type); //send message, that last message was received


private:
    static void sendMessage(char *message, uint16_t messageLength); //send message
};
