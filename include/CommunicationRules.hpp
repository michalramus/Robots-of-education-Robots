#include <WString.h>

#pragma once

enum CommSymbolID //id of communication symbols
{
    startEndMessage = 0, //symbol that is on the begin and end of message

    messageType, //types of message
    msgTypeError,
    msgTypeConfig,
    msgTypeInfo,
    msgTypeTask,

    symbolsTabSize, //ID is equal to symbols tab size. IT HAS TO BE AT THE END OF ENUM
};

enum DevType //ID of device types
{

};

class CommSymbol //communication symbols
{
public:
    static String getSymbol(uint16_t ID); //get symbols by ID

    static uint16_t getID(String symbol); //get ID of symbol
    static uint16_t getID(String symbol, uint16_t startID); //get ID of symbol Start search from specific ID

private:
    const static String SYMBOLS[]; //table with symbols
};
