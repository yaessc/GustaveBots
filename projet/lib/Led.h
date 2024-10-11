/*
 * Description: Classe permettant la gestion de la DEL.
 * Identifications matérielles : Broches au choix en mode sortie et reliées à la DEL.
 */

/*
 * Description: Class used to manage the LED.
 * Hardware identifications: Pins in output mode connected to the LED.
 */
#pragma once

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

class Led {
public:
    Led(volatile uint8_t* portX, 
        volatile uint8_t* ddrX, 
        uint8_t pinM,
        uint8_t pinP);

    void turnOnRed();
    void turnOnGreen();
    void turnOnAmber();
    void turnOff();
    ~Led() = default;
private:
    volatile uint8_t* _portX;
    uint8_t _pinM;
    uint8_t _pinP;
    static constexpr uint8_t DELAY_AMBER_RED = 5;
    static constexpr uint8_t DELAY_AMBER_GREEN = 10;
};