#include "IRReception.h"

IRReception::IRReception()
{
    DDRB |= (1 << PB0);
}

