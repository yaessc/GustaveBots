#include "Music.h"

Music::Music()
{
    DDRD |= (1 << PD6) | (1 << PD7);
}

void Music::playNote(uint8_t note)
{
    TCCR2A |= (1 << COM2A0) | (1 << WGM21);
    TCCR2B |= (1 << CS21) | (1 << CS20);

    uint16_t frequency = _frequencyList[note - 45];

    OCR2A = (F_CPU / ((2 * 64) * frequency)) - 1; ;
}

void Music::stopNote()
{
    TCCR2A &= ~(1 << COM2A0);
}