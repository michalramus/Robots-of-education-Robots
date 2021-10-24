#ifdef TEST


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
