#include "Writer.h"

Writer::Writer() : currentAddress(0x00) {}

void Writer::writeByte(uint8_t &byte)
{
    const uint8_t WRITING_DELAY = 5;

    byte = transmit.receive();
    eeprom.ecriture(currentAddress, byte);
    currentAddress++;
    _delay_ms(WRITING_DELAY);
}

void Writer::writeByteCode()
{
    uint8_t currentByte = 0;
    writeByte(currentByte);
    
    uint16_t byteCodeSize = currentByte;
    byteCodeSize = byteCodeSize << 8;

    writeByte(currentByte);
    byteCodeSize |= currentByte;

    while (currentAddress < byteCodeSize)
    {
        writeByte(currentByte);
    }
}
