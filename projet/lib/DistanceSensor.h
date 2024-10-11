/*
 * Description: Classe permettant la lecture et l'utilisation d'un capteur de distance.
 * Identifications matérielles : Broches PA0 en mode entrée et relié au capteur de distance.                           
 */

/*
 * Description: Class allowing the reading and use of a disctance sensor.
 * Hardware identifications: PA0 pins in input mode and connected to the distance sensor.                           
 */
#pragma once

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "can.h"

class DistanceSensor
{
public:
    DistanceSensor();
    uint8_t readDistance();
    bool isWallDetected();

private:
    const uint8_t _MIN_DETECTED_DISTANCE=10;
    const uint8_t _MAX_DETECTED_DISTANCE=79;
    can _converter;
};
