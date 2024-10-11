#include "IRTransmission.h"
IRTransmission::IRTransmission()
{
}
void IRTransmission::emitFrequency()
{
    cli();
    DDRD |= (1 << PD5);
    stopFrequency();
    OCR1A = F_CPU / (2 * TRANSMISSION_FREQUENCY * PRESCALER) - 1;
    TCCR1A |= (1 << COM1A0) | (1 << WGM12);
    TCCR1B |= (1 << CS11);
    sei();
}

void IRTransmission::stopFrequency()
{
    DDRD &= ~(1 << PD5);
    TCCR1A &= ~(1 << COM1A0);
}

void IRTransmission::startingSequence()
{
    emitFrequency();
    _delay_us(2400);
    stopFrequency();
    _delay_ms(600);
}
void IRTransmission::send1()
{
    emitFrequency();
    _delay_us(LONG_DELAY);
    stopFrequency();
    _delay_us(SHORT_DELAY);
}

void IRTransmission::send0()
{
    emitFrequency();
    _delay_us(SHORT_DELAY);
    stopFrequency();
    _delay_us(SHORT_DELAY);
}

void IRTransmission::transmitData(uint16_t command)
{
    startingSequence();
    for (int i = 0; i < 16; i++)
    {
        if ((command >> i) & 1)
        {
            send1();
        }
        else
        {
            send0();
        }
    }
}

void IRTransmission::readSegmentsFromMemory()
{
    uint8_t readValue = 0;
    uint16_t currentAddress = 0;

    for (uint8_t i = 0; i < 6; i++)
    {

        _memory.lecture(currentAddress++, &readValue);
        _delay_ms(5);
        _segmentsInfo[i][0] = readValue; 
        _delay_ms(5);

        _memory.lecture(currentAddress++, &readValue);
        _delay_ms(5);
        _segmentsInfo[i][1] = readValue; 
        _delay_ms(5);

        _memory.lecture(currentAddress++, &readValue);
        _delay_ms(5);
        _segmentsInfo[i][2] = readValue; 
        _delay_ms(5);
    }
}

void IRTransmission::transmitArray()
{

    readSegmentsFromMemory(); 

    startingSequence();
    for (int i = 0; i < 6; i++)
    { 
        for (int j = 0; j < 3; j++)
        { 
            uint16_t packet = 0;
            packet = _segmentsInfo[i][j]; 

            transmitData(packet); 
        }
    }
}