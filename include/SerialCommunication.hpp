#include "Message/Message.hpp"

#include <WString.h>

#pragma once
class SerialCommunication
{
public:
    static void setBaudRate(uint16_t baudRate);

    static Message &readMessage(); //read values from Serial
    
    static void sendMessage(Message message); //send message
    static void sendMessage(char message[]); //send message
    static void sendLastMessage(); //send last message
    static void sendMessageReceived(); //send message, that last message was received
    
private:

    static char *lastReceivedMessage;
};
