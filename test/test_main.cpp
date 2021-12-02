#ifdef ARDUINO //check if started Arduino tests...


#include "Process.hpp"

#include <Arduino.h>
#include <unity.h>

void setup()
{
    UNITY_BEGIN();
    process(); //run tests
    UNITY_END();
}

void loop() //signalize tests' end on Arduino led
{
    //empty
}

#endif

#ifdef NATIVE //...or native tests

int main()
{
    return 0;
}

#endif
