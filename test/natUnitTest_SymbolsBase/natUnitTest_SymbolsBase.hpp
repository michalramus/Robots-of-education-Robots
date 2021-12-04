#include "Symbols/Symbols.hpp"
#include <unity.h>


#ifndef NATIVE_UNIT_TEST_SYMBOLS_BASE_HPP
#define NATIVE_UNIT_TEST_SYMBOLS_BASE_HPP

class natUnitTest_SymbolsBase
{
    public:

    //getSymbol
    static void natUnitTest_getSymbol_getCorrectSymbol()
    {
        TEST_ASSERT(SymbolsBase::getSymbol(0) == "x");
        TEST_ASSERT(SymbolsBase::getSymbol(3) == "config");
        TEST_ASSERT(SymbolsBase::getSymbol(5) == "task");
    }

    static void natUnitTest_getSymbol_TryToGetSymbolByIncorrectID()
    {
    }

    //getID 1arg
    static void natUnitTest_getID_1arg_getCorrectID()
    {
    }

    static void natUnitTest_getID_1arg_tryToGetIDByIncorrectSymbol()
    {
    }

    //getID 2arg
    static void natUnitTest_getID_2arg_getCorrectID()
    {
    }

    static void natUnitTest_getID_2arg_tryToGetIDByIncorrectSymbol()
    {
    }

    static void natUnitTest_getID_2arg_tryToGetIDWithIncorrectStartID()
    {
    }

    static void natUnitTest_getID_2arg_tryToGetIDWithIncorrectStartIDAndSymbol()
    {

    }


    //start unit tests
    static void natUnitTest_SymbolsBase_process() //call all tests
    {

    }
};

#endif
