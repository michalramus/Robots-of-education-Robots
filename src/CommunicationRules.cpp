#include <CommunicationRules.hpp>

const String CommSymbol::symbols[] = {"x"}; //table with symbols

String CommSymbol::getSymbol(int ID)
{
    return symbols[ID];
}

int CommSymbol::getID(String symbol)
{
    //TODO: create getID method body
}
