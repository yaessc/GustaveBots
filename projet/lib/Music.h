/*
 * Description: Classe permettant la gestion du buzzer piézoélectrique.
 * Identifications matérielles : Broches PD6 et PD7  en mode sortie et reliées au buzzer                          
 */

/*
 * Description: Class used to control the piezoelectric buzzer.
 * Hardware identification: PD6 and PD7 pins in output mode and connected to the buzzer.                          
 */
#pragma once
#define F_CPU 8000000UL
#include <avr/io.h>
class Music
{
public:
    Music();
    void playNote(uint8_t note);
    void stopNote();
private:
    uint16_t _frequencyList[37]={110, 117, 123, 131, 139, 147, 156, 165, 175,
     185, 196, 208, 220, 233, 247, 262, 277, 294, 311, 330, 349, 370, 392, 415,
     440, 466, 494, 523, 554, 587, 622, 659, 698, 740, 784, 831, 880};
};

