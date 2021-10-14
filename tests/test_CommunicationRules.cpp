#include "CommunicationRules.hpp"
#include <unity.h>
//getSymbol
void test_getSymbol_getCorrectSymbol(void)
{
    
}

void test_getSymbol_TryToGetSymbolByIncorrectID(void)
{

}

//getID 1arg
void test_getID_1arg_getCorrectID(void)
{

}

void test_getID_1arg_tryToGetIDByIncorrectSymbol(void)
{

}

//getID 2arg
void test_getID_2arg_getCorrectID(void)
{

}

void test_getID_2arg_tryToGetIDByIncorrectSymbol(void)
{

}

void test_getID_2arg_tryToGetIDWithIncorrectStartID(void)
{

}

void test_getID_2arg_tryToGetIDWithIncorrectStartIDAndSymbol(void)
{

}

void test_CommunicationRules_process() //call all tests
{
    RUN_TEST(test_getSymbol_getCorrectSymbol);
    RUN_TEST(test_getSymbol_TryToGetSymbolByIncorrectID);

    RUN_TEST(test_getID_1arg_getCorrectID);
    RUN_TEST(test_getID_1arg_tryToGetIDByIncorrectSymbol);
    
    RUN_TEST(test_getID_2arg_getCorrectID);
    RUN_TEST(test_getID_2arg_tryToGetIDByIncorrectSymbol);
    RUN_TEST(test_getID_2arg_tryToGetIDWithIncorrectStartID);
    RUN_TEST(test_getID_2arg_tryToGetIDWithIncorrectStartIDAndSymbol);
}
