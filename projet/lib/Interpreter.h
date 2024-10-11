/*
 * Description: Classe permettant la lecture et l'interprétation de bytecode écrit dans la mémoire externe du robot.           
 */
/*
 * Description: Class for reading and interpreting bytecode written in the robot's external memory.           
 */
#pragma once
#define F_CPU 8000000UL
#include "Led.h"
#include "Music.h"
#include "Motors.h"
#include "Transmission.h"
#include "util/delay.h"
#include "memoire_24.h"

class Interpreter
{
public:
    enum Instruction : uint8_t
    {
        DBT = 0x01,
        ATT = 0x02,
        DAL = 0x44,
        DET = 0x45,
        SGO = 0x48,
        SAR = 0x09,
        MAR = 0x60,
        MAR2 = 0x61,
        MAV = 0x62,
        MRE = 0x63,
        TRD = 0x64,
        TRG = 0x65,
        DBC = 0xC0,
        FBC = 0xC1,
        FIN = 0xFF
    };

    Interpreter();
    void readByteCode();

private:
    void interpretInstruction(uint8_t instruction, uint8_t operand);
    Transmission _communications;
    Motors _wheels;
    Memoire24CXXX _memory;
    Led _led;
    Music _music;
    uint16_t _currentAddress = 0;
    uint16_t _loopAddress = 0;
    uint8_t _counter = 0;
};
