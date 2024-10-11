/*
 * Description: Classe permettant la gestion de la communication UART.
 * Identifications matérielles : Broches PD0 et PD1.
 */

/*
 * Description: Class used to manage UART communication.
 * Hardware identification: PD0 and PD1 pins.
 */
#pragma once

#include <avr/io.h>
#include <stdio.h>

class Transmission
{
public:
    Transmission();

    static void initialisation();
    static void transmit(char data);
    static void transmit(const char *data);

    static uint8_t receive();
    static void transmitMessage(const char message[]);
    static void transmitMessageValue(const char message[], uint8_t value);
};
