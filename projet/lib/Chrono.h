#pragma once

#include <avr/io.h>

class Chrono
{
public:
    Chrono();
    void RestartChrono();
    uint16_t getCurrentTime();

};


