#pragma once

enum SymbolsIDs //id of communication symbols
{
    startEndMessage = 0, //symbol that is on the begin and end of message

    //types of message
    messageType,

    msgTypeError, //error message

    msgTypeConfig, //config message
    msgConfDeviceTypes,

    msgTypeInfo, //info message

    msgTypeTask, //task message
    msgTaskTaskNumber,
    msgTaskDeviceType,
    msgTaskTaskType,
    msgTaskExtraValNum,
    msgTaskExtraVal,

    //devices
    deviceID,
    pinsArray, //array of pins used by device

    symbolsTabSize, //ID is equal to symbols tab size. IT HAS TO BE AT THE END OF ENUM
};
