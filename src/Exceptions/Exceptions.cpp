#include "Exceptions/Exceptions.hpp"
#include "SerialCommunication.hpp"

void Exceptions::throwException(IMessage message)
{
    if (!_sendMessage) //check if _sendMessage method was set
    {
        _sendMessage = &SerialCommunication::sendMessage;
    }

    _sendMessage(message); //send error msg
    
    freezeController();
}

void Exceptions::setCommunication(void (*sendMessage)(IMessage))
{
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
