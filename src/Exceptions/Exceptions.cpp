#include "Exceptions/Exceptions.hpp"
#include "SerialCommunication.hpp"
#include "Message/Error.hpp"
#include "Message/Message.hpp"

//create class-static variables
void (*Exceptions::_sendMessage)(IMessage &) = nullptr; //communication interface
IMessage *Exceptions::_message = nullptr;  //message to send

bool Exceptions::exceptionCalled = false;


void Exceptions::throwException(Error error)
{
    if (exceptionCalled == false) //check if exception was already thrown
    {
        exceptionCalled = true;

        if (!_sendMessage) //check if _sendMessage method was set
        {
            _sendMessage = &SerialCommunication::sendMessage;
        }

        if (!_message) //check if Message object was created
        {
            _message = new Message;
        }

        _message->setMessageByError(error);

        _sendMessage(*_message); //send error msg
    }

    freezeController();
}

void Exceptions::setCommunication(IMessage *message, void (*sendMessage)(IMessage&))
{
    _message = message;
    _sendMessage = sendMessage;
}

void Exceptions::freezeController()
{
#ifndef TEST
    while (true) //freeze microcontroller
    {
        {
            //empty
        }
    }
#endif
}
