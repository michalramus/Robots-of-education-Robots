#include <Arduino.h>

#pragma once

enum CommSymbolID //id of communication symbols
{
    startEndMessage = 0, //symbol that is on the begin and end of message

};

enum DevType //ID of device types
{

};

class CommSymbol //communication symbols
{
public:
    static String getSymbol(int ID); //get symbols by ID
    static int getID(String symbol); //get ID of symbol

private:
    const static String symbols[]; //table with symbols
};
