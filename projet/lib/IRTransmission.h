/*
 * Description: Classe permettant la gestion des interruptions externes avec un/des boutons.
 * Identifications matérielles : Broches PD2,PD3 ou PB2 en mode entrée et reliée au bouton poussoir                           
 */

/*
 * Description: Class for managing external interrupts with one or more buttons.
 * Hardware identification: PD2, PD3 or PB2 pins in input mode and connected to the pushbutton.                           
 */
#pragma once

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "memoire_24.h"
#include <util/crc16.h>

const uint16_t TRANSMISSION_FREQUENCY = 38000;
const uint16_t LONG_DELAY = 1200;
const uint16_t SHORT_DELAY = 600;
const uint8_t PRESCALER = 8;

class IRTransmission
{
public:
    IRTransmission();
    void emitFrequency();
    void stopFrequency();
    void startingSequence();
    void send1();
    void send0();
    void readSegmentsFromMemory();
    void transmitData(uint16_t command);
    void transmitArray();


private:
    Memoire24CXXX _memory;
    uint8_t _segmentsInfo[6][3];
};
