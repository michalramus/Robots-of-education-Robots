#include "test_Exceptions/test_Exceptions.hpp"

#include "test_Message/test_Device.hpp"
#include "test_Message/test_Message.hpp"

#include "test_SerialComunication/test_SerialCommunication.hpp"

#include "test_SymbolsBase/test_SymbolsBase.hpp"



#ifndef PROCESS_HPP
#define PROCESS_HPP

void process()//function that contain all process functions
{
    test_Exceptions_process();

    test_Device_process();
    test_Message_process();

    test_SerialCommunication_process();

    test_SymbolsBase_process();
}

#endif
