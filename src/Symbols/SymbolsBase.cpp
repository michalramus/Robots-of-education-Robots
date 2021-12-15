#include "Symbols/SymbolsBase.hpp"
#include "Symbols/SymbolsIDs.hpp"
#include "Exceptions/Exceptions.hpp"

#ifndef NATIVE
#include <WString.h>
#else
#include <ArduinoFake.h>
#endif

void (*SymbolsBase::_throwException)(Error error);

//TODO: optimize SYMBOLS
const String SymbolsBase::SYMBOLS[] = {
    "x",

    "type",
    "error",
    "config", "devTypes",
    "information",
    "task", "taskNum", "devType", "taskType", "valNum", "value",
    "ID", "pins"}; //table with symbols

String SymbolsBase::getSymbol(int16_t ID)
{
    return SYMBOLS[ID];
}

int16_t SymbolsBase::getID(String symbol) //get ID of symbol
{
    return SymbolsBase::getID(symbol, 0);
}

int16_t SymbolsBase::getID(String symbol, int16_t startID) //get ID of symbol Start search from specific ID
{
    if (!_throwException) //check if _throwException was set
    {
        _throwException = &Exceptions::throwException;
    }

    for (int i = startID; i < symbolsTabSize; i++) //iterate by table from startID
    {
        if (SymbolsBase::SYMBOLS[i] == symbol) //check symbol
        {
            return i;
        }
    }

    //create Error
    Error error;

    //rewrite symbol to char array
    char symbolChar[symbol.length()];

    for (uint8_t i = 0; i < symbol.length(); i++)
    {
        symbolChar[i] = symbol[i];
    }

    //throw exception
    error.setError(ExceptionsBase::incorrectSymbol, "Symbol not found", symbolChar);
    _throwException(error);

    return 0; //it is not possible to reach this line
}

void SymbolsBase::setExceptionMethod(void (*throwException)(Error error))
{
    SymbolsBase::_throwException = throwException;
}
