#pragma once

enum SymbolsIDs //id of communication symbols
{
    startEndMessage = 0, //symbol that is on the begin and end of message

    messageType, //types of message
    msgTypeError,
    msgTypeConfig,
    msgTypeInfo,
    msgTypeTask,

    symbolsTabSize, //ID is equal to symbols tab size. IT HAS TO BE AT THE END OF ENUM
};
