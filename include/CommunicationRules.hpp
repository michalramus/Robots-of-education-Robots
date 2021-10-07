#include <Arduino.h>

enum CommCharID //id of communication characters
{
    startEndMessage = 0, //symbol that is on the begin and end of message

};

class CommChar //communication characters
{
public:
    static char getChar(int ID); //get character by ID
    static int getID(char character); //get ID of character

private:
    const static char characters[]; //table with characters
};

const char CommChar::characters[] = {'x'};

char CommChar::getChar(int ID)
{
    return characters[ID];
}

int CommChar::getID(char character)
{
    
}
