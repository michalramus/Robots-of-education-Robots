#ifdef NATIVE
    #include <ArduinoFake.h>
#endif

#include "Symbols/Symbols.hpp"
#include <unity.h>


#ifndef NATIVE_UNIT_TEST_SYMBOLS_BASE_HPP
#define NATIVE_UNIT_TEST_SYMBOLS_BASE_HPP

class natUnitTest_SymbolsBase
{
public:
    //getSymbol
    static void natUnit_getSymbol_getCorrectSymbol_returnSymbol(int ID,  char Symbol[])
    {
        TEST_ASSERT_EQUAL_STRING(Symbol, SymbolsBase::getSymbol(ID).c_str());
    }


    static void natUnit_getSymbol_TryToGetSymbolByIncorrectID_throwException()
    {
    }

    //getID 1arg
    static void natUnit_getID_1arg_getCorrectID_returnID()
    {
    }


    static void natUnit_getID_1arg_tryToGetIDByIncorrectSymbol_throwException()
    {
    }

    //getID 2arg
    static void natUnit_getID_2arg_getCorrectID_returnID()
    {
    }

    static void natUnit_getID_2arg_tryToGetIDByIncorrectSymbol_throwException()
    {
    }

    static void natUnit_getID_2arg_tryToGetIDWithIncorrectStartID_throwException()
    {
    }

    static void natUnit_getID_2arg_tryToGetIDWithIncorrectStartIDAndSymbol_throwExcpetion()
    {
    }

    //start unit tests
    static void natUnitTest_SymbolsBase_process() //call all tests
    {
    }
};

#endif
