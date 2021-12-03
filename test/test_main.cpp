#include <unity.h>


#ifdef ARDUINO //check if started Arduino tests...

#include <Arduino.h>

#include "Process.hpp"


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
    UNITY_BEGIN();
    process(); //run tests
    UNITY_END();

    return 0;
}

#endif
