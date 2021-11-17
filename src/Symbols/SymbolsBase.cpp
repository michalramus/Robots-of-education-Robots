#include "Symbols/SymbolsBase.hpp"
#include "Symbols/SymbolsIDs.hpp"

#include <WString.h>

//TODO: optimize SYMBOLS
const String SymbolsBase::SYMBOLS[] = {
    "x",

    "type",
    "error",
    "config", "devTypes",
    "information",
    "task",
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
    for (int i = startID; i < symbolsTabSize; i++) //iterate by table from startID
    {
        if (SymbolsBase::SYMBOLS[i] == symbol) //check symbol
        {
            return i;
        }
    }
    //TODO: throw the exception
}
