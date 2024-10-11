#include "Transmission.h"

Transmission::Transmission()
{
    initialisation();
}

void Transmission::initialisation()
{
    UBRR0H = 0;
    UBRR0L = 0xCF;

    UCSR0A |= (1 << RXC0) | (1 << TXC0);
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}

void Transmission::transmit(char data)
{
    while (!(UCSR0A & (1 << UDRE0)))
        ;
    UDR0 = data;
}

void Transmission::transmit(const char *data)
{
    while (*data != '\0')
    {
        while (!(UCSR0A & (1 << UDRE0)))
            ;
        UDR0 = *data;
        ++data;
    }
}

uint8_t Transmission::receive()
{
    while (!(UCSR0A & (1 << RXC0)))
        ;
    return UDR0;
}

void Transmission::transmitMessage(const char message[])
{
    char buffer[50];
    int length;
    length = sprintf(buffer, message);
    for (uint8_t i = 0; i < length; i++)
        transmit(buffer[i]);
}

void Transmission::transmitMessageValue(const char message[], uint8_t value)
{
    char buffer[50];
    int length;
    length = sprintf(buffer, message, value);

    for (uint8_t i = 0; i < length; i++)
        transmit(buffer[i]);
}
