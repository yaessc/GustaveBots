/*
 * Description: Classe permettant la gestion des interruptions externes avec un/des boutons.
 * Identifications matérielles : Broches PD2,PD3 ou PB2 en mode entrée et reliée au bouton poussoir                           
 */
#pragma once
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
class Button
{
public:
    Button(uint8_t nInt);
    
    void interruptAnyEdge();
    void interruptRisingEdge();
    void interruptFallingEdge();
    void interruptReset();
    void interruptEnable();
    void interruptDisable();
    bool gButtonPressed;

private:
    uint8_t _nInt;
};