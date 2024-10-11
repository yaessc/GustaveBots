/*
 * Description: Classe générale permettant l'utilisation de toute les autre classes
 * Identifications matérielles : Robot 1: Capteur de distance sur PA0, Piezo sur PD6 et PD7, DEL sur PD4 et PD5, broches E et D de JM2 du pont H sur PD4 et PD6, broches E et D de JM1 du pont H sur PD5 et PD7.
 * Robot 2: Suiveur de ligne D1 sur PA0, D2 sur PA1, D3 sur PA2, D4 sur PA3, D5 sur PA4, Piezo sur PD6 et PD7, DEL sur PD4 et PD5, broches E et D de JM2 du pont H sur PD4 et PD6, broches E et D de JM1 du pont H sur PD5 et PD7.                          
 */

/*
 * Description: General class allowing the use of all other classes.
 * Hardware identifications: Robot 1: Distance sensor on PA0, Piezo on PD6 and PD7, LED on PD4 and PD5, pins E and D of JM2 on H-bridge on PD4 and PD6, pins E and D of JM1 on H-bridge on PD5 and PD7.
 * Robot 2: Line follower D1 on PA0, D2 on PA1, D3 on PA2, D4 on PA3, D5 on PA4, Piezo on PD6 and PD7, LED on PD4 and PD5, H-bridge pins E and D JM2 on PD4 and PD6, H-bridge pins E and D JM1 on PD5 and PD7.                          
 */

#pragma once

#define F_CPU 8000000UL

#include <avr/io.h>
#include "Button.h"
#include "DistanceSensor.h"
#include "Led.h"
#include "lineSensor.h"
#include "MapTransmitter.h"
#include "Motors.h"
#include "Music.h"
#include "Positioning.h"
#include "Timer1.h"
#include "Transmission.h"
#include "util/delay.h"

class Robot
{
private:
    Button _button1;
    Button _button2;
    Led _led;
    Motors _wheels;
    Music _music;
    DistanceSensor _distanceSensor;
    Positioning _position;
    Timer1 _timer1;
    Transmission _rs232;
    MapTransmitter _map;
    LineSensor _line;

public:
    Robot();
    void interruptAnyEdgeButton1();
    void interruptRisingEdgeButton1();
    void interruptFallingEdgeButton1();
    void interruptResetButton1();
    void interruptEnableButton1();
    void interruptDisableButton1();
    volatile bool gButton1Pressed = false;
    const uint8_t BUTTON1_MASK = (1 << PD2);

    void interruptAnyEdgeButton2();
    void interruptRisingEdgeButton2();
    void interruptFallingEdgeButton2();
    void interruptResetButton2();
    void interruptEnableButton2();
    void interruptDisableButton2();
    volatile bool gButton2Pressed = false;
    const uint8_t BUTTON2_MASK = (1 << PD3);

    uint8_t readDistance();
    bool isWallDetected();
    uint8_t desiredDistance;

    void turnOnLedRed();
    void turnOnLedGreen();
    void turnOffLed();

    void followLine();

    void stopMotors();
    void moveForward(uint8_t leftPercentage, uint8_t rightPercentage);
    void moveBackwards(uint8_t leftPercentage, uint8_t rightPercentage);
    void turnRight();
    void turnLeft();
    uint8_t turnRightCounter = 0;
    uint8_t turnLeftCounter = 0;

    void playNote(uint8_t note);
    void stopNote();

    void moveToCenter();
    void faceExit();

    void initialisation();
    void transmit(char data);
    void transmit(const char *data);

    void startTimer1(uint16_t durationMs, uint16_t start);
    volatile bool gTimer1Expired = false;

    uint8_t receive();
    void transmitMessage(const char message[]);
    void transmitMessageValue(const char message[], uint8_t value);
    void transmitMap();
    bool isTransmittingMap;

    void stopRobot();
};