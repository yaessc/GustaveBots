#include "Chrono.h"
Chrono::Chrono()
{
    TCCR1A = ~((1 << WGM10) | (1 << WGM11));
    TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS10) | (1 << CS12);
    TCCR1C = 0;
    TIMSK1 &= ~((1 << OCIE1A) | (1 << OCIE1B));
    TCNT1 = 0;
}
void Chrono::RestartChrono()
{
    TCNT1 = 0;
}
uint16_t Chrono::getCurrentTime()
{
    return (TCNT1 / 8) / 25;
}