#include <Arduino.h>

enum CommCharID //id of communication characters
{
    startEndMessage = 0, //symbol that is on the begin and end of message

};

class CommChar //communication characters
{
public:
    static char get(int ID); //get character by ID

private:
    const static char characters[]; //table with characters
};

const char CommChar::characters[] = {'x'};

char CommChar::get(int ID)
{
    return characters[ID];
}
