#include "Process.cpp"

#pragma once

#ifdef ARDUINO //check if tests are running on Arduino
//if testing on Arduino ...

#include <Arduino.h>

void setup()
{
    process(); //run tests
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
    process(); //run tests

    return 0;
}

#endif
