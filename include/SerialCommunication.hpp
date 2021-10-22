#include <Arduino.h>

#pragma once
class SerialCommunication
{
public:
    static void setBaudRate(uint16_t baudRate);

    static String readMessage(); //read values from Serial
    
    static void sendMessage(String message); //send message
    static void sendLastMessage(); //send last message
    static void sendMessageReceived(); //send message, that last message was received
    
private:

    static String lastReceivedMessage;
};
