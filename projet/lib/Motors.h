/*
 * Description: Classe permettant la gestion de la motricité du robot.
 * Identifications matérielles : Broches PB4, PB6 en mode sortie et reliées respectivement à E et D de JM2 sur le pont H .
 *                               Broches PB3, PB5 en mode sortie et reliées respectivement à E et D de JM1 sur le pont H .
 */

/*
 * Description: Class used to manage the robot's motricity.
 * Hardware identifications: Pins PB4, PB6 in output mode and connected respectively to E and D of JM2 on H-bridge .
 * Pins PB3, PB5 in output mode and connected respectively to E and D of JM1 on H-bridge .
 */
#pragma once
#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
const uint8_t LEFT_WHEEL=(1<<PB4);
const uint8_t LEFT_DIRECTION=(1<<PB6);
const uint8_t RIGHT_WHEEL=(1<<PB3);
const uint8_t RIGHT_DIRECTION=(1<<PB5);
const uint8_t MAX_SPEED=255;
const uint8_t STOPPED_SPEED=0;
const uint8_t ONE_HUNDRED=100;
const uint8_t FIFTY=50;


class Motors
{
public:
    Motors();
    void stop();
    void moveForward(uint8_t leftWheelPercentage,uint8_t rightWheelPercentage);
    void moveBackwards(uint8_t leftWheelPercentage,uint8_t rightWheelPercentage);
    void turnLeft();
    void turnRight();
    void adjustMotorSpeed(uint8_t leftWheelPercentage,uint8_t rightWheelPercentage);
    uint8_t turnRightCounter=0;
    uint8_t turnLeftCounter=0;

};


