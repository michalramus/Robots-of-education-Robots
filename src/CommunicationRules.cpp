#include "CommunicationRules.hpp"
#include <WString.h>

const String CommSymbol::symbols[] = {
                                        "x",
                                        "type", "error", "config", "information", "task"}; //table with symbols

String CommSymbol::getSymbol(int ID)
{
    return symbols[ID];
}

int CommSymbol::getID(String symbol) //get ID of symbol
{
    return CommSymbol::getID(symbol, 0);
}

int CommSymbol::getID(String symbol, int startID) //get ID of symbol Start search from specific ID
{
    for (int i = startID; i < symbolsTabSize; i++) //iterate by table from startID
    {
        if (CommSymbol::symbols[i] == symbol) //check symbol
        {
            return i;
        }
    }
    //TODO: throw the exception
}
