#include "CommunicationRules.hpp"
#include <unity.h>

class test_CommunicationRules
{
    public:

    //getSymbol
    static void test_getSymbol_getCorrectSymbol()
    {
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

void test_CommunicationRules_process() //call all tests
{
    RUN_TEST(test_CommunicationRules::test_getSymbol_getCorrectSymbol);
    RUN_TEST(test_CommunicationRules::test_getSymbol_TryToGetSymbolByIncorrectID);

    RUN_TEST(test_CommunicationRules::test_getID_1arg_getCorrectID);
    RUN_TEST(test_CommunicationRules::test_getID_1arg_tryToGetIDByIncorrectSymbol);

    RUN_TEST(test_CommunicationRules::test_getID_2arg_getCorrectID);
    RUN_TEST(test_CommunicationRules::test_getID_2arg_tryToGetIDByIncorrectSymbol);
    RUN_TEST(test_CommunicationRules::test_getID_2arg_tryToGetIDWithIncorrectStartID);
    RUN_TEST(test_CommunicationRules::test_getID_2arg_tryToGetIDWithIncorrectStartIDAndSymbol);
}
