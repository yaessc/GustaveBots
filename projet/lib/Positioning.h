/*
 * Description: Classe permettant la gestion du positionnement du robot 1 selon les valeurs lues par le capteur de distance.
 * Identifications matérielles : Capteur de distance sur PA0 en mode entrée, broches E et D de JM2 du pont H sur PD4 et PD6 en mode sortie, broches E et D de JM1 du pont H sur PD5 et PD7 en mode sortie.
 */
/*
 * Description: This class controls the positioning of robot 1 according to the values read by the distance sensor.
 * Hardware identifications: Distance sensor on PA0 in input mode, pins E and D of JM2 of H-bridge on PD4 and PD6 in output mode, pins E and D of JM1 of H-bridge on PD5 and PD7 in output mode.
 */
#pragma once

#include "Motors.h"
#include "DistanceSensor.h"

class Positioning
{
private:
    uint8_t _desiredDistance = 50;
    Motors _wheels;
    DistanceSensor _distance;

public:
    Positioning();
    void moveToCenter();
    void faceExit();
    uint8_t getDesiredDistance();
    uint8_t turnRightCounter = 0;
    uint8_t turnLeftCounter = 0;
};
