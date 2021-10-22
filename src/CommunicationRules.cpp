#include "CommunicationRules.hpp"
#include <WString.h>

const String CommSymbol::SYMBOLS[] = {
                                        "x",
                                        "type", "error", "config", "information", "task"}; //table with symbols

String CommSymbol::getSymbol(uint16_t ID)
{
    return SYMBOLS[ID];
}

uint16_t CommSymbol::getID(String symbol) //get ID of symbol
{
    return CommSymbol::getID(symbol, 0);
}

uint16_t CommSymbol::getID(String symbol, uint16_t startID) //get ID of symbol Start search from specific ID
{
    for (int i = startID; i < symbolsTabSize; i++) //iterate by table from startID
    {
        if (CommSymbol::SYMBOLS[i] == symbol) //check symbol
        {
            return i;
        }
    }
    //TODO: throw the exception
}
