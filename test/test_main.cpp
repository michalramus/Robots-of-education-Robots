#include <unity.h>
#include "Process.cpp"

#ifndef TEST_MAIN.CPP
#define TEST_MAIN.CPP

#ifdef ARDUINO //check if tests are running on Arduino
//if testing on Arduino ...

#include <Arduino.h>

void setup()
{
    UNITY_BEGIN();
    process(); //run tests
    UNITY_END();
}

void loop() //signalize tests' end on Arduino led
{
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(500);
}

#else // ... or on emulator

int main(int argc, char **argv)
{
    UNITY_BEGIN();
    process(); //run tests
    UNITY_END();

    return 0;
}

#endif

#endif
