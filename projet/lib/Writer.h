/*
 * Description: Classe permettant l'écriture de bytecode dans la mémoire externe du robot
 */

/*
 * Description: class for writing bytecode to the robot's external memory
 */
#pragma once

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "memoire_24.h"
#include "Transmission.h"

class Writer {
private:
    Memoire24CXXX eeprom;
    Transmission transmit;
    uint16_t currentAddress;
public:
    Writer();

    void writeByte(uint8_t &byte);

    void writeByteCode();
};

