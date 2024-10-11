/*
 * Description: Classe permettant la gestion de la minuterie TIMER1.
 */

/*
 * Description: Class used to manage the TIMER1 timer.
 */
#pragma once

#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 8000000UL

class Timer1
{
public:

  void startTimer1(uint16_t durationMs, uint16_t start);

 volatile bool gTimerExpired;
};
