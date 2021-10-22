#include "Symbols/Symbols.hpp"
#include <unity.h>


#ifndef TEST_COMMUNICATION_RULES_HPP
#define TEST_COMMUNICATION_RULES_HPP

class test_SymbolsBase
{
    public:

    //getSymbol
    static void test_getSymbol_getCorrectSymbol()
    {
        TEST_ASSERT(SymbolsBase::getSymbol(0) == "x");
        TEST_ASSERT(SymbolsBase::getSymbol(3) == "config");
        TEST_ASSERT(SymbolsBase::getSymbol(5) == "task");
    }

    static void test_getSymbol_TryToGetSymbolByIncorrectID()
    {
    }

    //getID 1arg
    static void test_getID_1arg_getCorrectID()
    {
    }

    static void test_getID_1arg_tryToGetIDByIncorrectSymbol()
    {
    }

    //getID 2arg
    static void test_getID_2arg_getCorrectID()
    {
    }

    static void test_getID_2arg_tryToGetIDByIncorrectSymbol()
    {
    }

    static void test_getID_2arg_tryToGetIDWithIncorrectStartID()
    {
    }

    static void test_getID_2arg_tryToGetIDWithIncorrectStartIDAndSymbol()
    {

    }

};

void test_SymbolsBase_process() //call all tests
{
    RUN_TEST(test_SymbolsBase::test_getSymbol_getCorrectSymbol);
    RUN_TEST(test_SymbolsBase::test_getSymbol_TryToGetSymbolByIncorrectID);

    RUN_TEST(test_SymbolsBase::test_getID_1arg_getCorrectID);
    RUN_TEST(test_SymbolsBase::test_getID_1arg_tryToGetIDByIncorrectSymbol);

    RUN_TEST(test_SymbolsBase::test_getID_2arg_getCorrectID);
    RUN_TEST(test_SymbolsBase::test_getID_2arg_tryToGetIDByIncorrectSymbol);
    RUN_TEST(test_SymbolsBase::test_getID_2arg_tryToGetIDWithIncorrectStartID);
    RUN_TEST(test_SymbolsBase::test_getID_2arg_tryToGetIDWithIncorrectStartIDAndSymbol);
}

#endif
