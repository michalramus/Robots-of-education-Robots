#include <unity.h>


#ifdef ARDUINO //check if started Arduino tests...

#include <Arduino.h>
#include "CommonProcess.hpp"

void setup()
{
    UNITY_BEGIN();
    comProcess(); //run tests
    UNITY_END();
}

void loop() //signalize tests' end on Arduino led
{
    //empty
}

#else //...or native tests

#include "NativeProcess.hpp"

int main()
{
    UNITY_BEGIN();
    natProcess(); //run tests
    UNITY_END();

    return 0;
}

#endif
