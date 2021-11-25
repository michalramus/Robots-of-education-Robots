#include "Exceptions/Exceptions.hpp"
#include "SerialCommunication.hpp"
#include "Message/Error.hpp"
#include "Message/Message.hpp"

void Exceptions::throwException(Error error)
{
    if (!_sendMessage) //check if _sendMessage method was set
    {
        _sendMessage = &SerialCommunication::sendMessage;
    }

    if(!_message) //check if Message object was created
    {
        _message = new Message;
    }

    _message->setMessageByError(error);

    _sendMessage(*_message); //send error msg
    
    freezeController();
}

void Exceptions::setCommunication(IMessage *message, void (*sendMessage)(IMessage))
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
