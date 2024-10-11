#include "Timer1.h"

void Timer1::startTimer1(uint16_t durationMs, uint16_t start)
{
    gTimerExpired = false;
    TCNT1 = start;
    OCR1A = ((F_CPU / 1024) / 1000) * durationMs;
    TCCR1A = 0;
    TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10);
    TCCR1C = 0;
    TIMSK1 = 1 << OCIE1A;
}
