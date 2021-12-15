#include "Message/Error.hpp"

#ifndef NATIVE
#include <WString.h>
#else
#include <ArduinoFake.h>
#endif

#pragma once

class SymbolsBase //communication symbols
{
public:
    static String getSymbol(int16_t ID); //get symbols by ID

    static int16_t getID(String symbol);                  //get ID of symbol
    static int16_t getID(String symbol, int16_t startID); //get ID of symbol Start search from specific ID

    static void setExceptionMethod(void (*throwException)(Error error));

private:
    const static String SYMBOLS[]; //table with symbols
    static void (*_throwException)(Error error);
};
