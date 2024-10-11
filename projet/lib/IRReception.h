/*
 * Description: Classe permettant la réception de signaux infrarouges.
 * Identifications matérielles : Broches PB0 en mode entrée reliée à au photodétecteur infrarouge                  
 */

/*
 * Description: Class for receiving infrared signals.
 * Hardware identification: PB0 pins in input mode connected to infrared photodetector.                  
 */
#pragma once

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "memoire_24.h"
class IRReception
{
private:
    Memoire24CXXX _memory;
    uint8_t _segmentsInfo[6][3];
public:
    IRReception();
    
};

