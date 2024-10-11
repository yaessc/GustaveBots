#include "Interpreter.h"

Interpreter::Interpreter() : _led(&PORTA, &DDRA, PA0, PA1) {}

void Interpreter::readByteCode()
{
    const uint8_t READING_DELAY = 5;
    uint8_t byteCode = 0x00;
    uint8_t operand = 0;
    bool isRunning = false;
    while (true)
    {
        _memory.lecture(_currentAddress, &byteCode);
        _currentAddress++;
        _delay_ms(READING_DELAY);

        _memory.lecture(_currentAddress, &operand);
        _currentAddress++;
        _delay_ms(READING_DELAY);

        if (byteCode == Interpreter::DBT)
            isRunning = true;
        if (isRunning)
            interpretInstruction(byteCode, operand);
        if (byteCode == Interpreter::FIN)
        {
            isRunning = false;
            break;
        }
    }
}

void Interpreter::interpretInstruction(uint8_t instruction, uint8_t operand)
{
    const uint8_t ATT_DELAY = 25;

    switch (instruction)
    {
    case Interpreter::ATT:
        for (uint8_t i = 0; i < operand; i++)
        {
            _delay_ms(ATT_DELAY);
        }
        break;
    case Interpreter::DAL:
        switch (operand)
        {
        case 1:
            _led.turnOnRed();
            break;
        case 2:
            _led.turnOnGreen();
            break;
        }
        break;
    case Interpreter::DET:
        _led.turnOff();
        break;
    case Interpreter::SGO:
        _music.playNote(operand);
        break;
    case Interpreter::SAR:
        _music.stopNote();
        break;
    case Interpreter::MAR: // Fallthrough
    case Interpreter::MAR2:
        _wheels.stop();
        break;
    case Interpreter::MAV:
        _wheels.moveForward(operand * 100 / 255, operand * 100 / 255);
        break;
    case Interpreter::MRE:
        _wheels.moveBackwards(operand * 100 / 255, operand * 100 / 255);
        break;
    case Interpreter::TRD:
        _wheels.turnRight();
        break;
    case Interpreter::TRG:
        _wheels.turnLeft();
        break;
    case Interpreter::DBC:
        _loopAddress = _currentAddress;
        _counter = operand + 1;
        break;

    case Interpreter::FBC:
        _counter--;
        if (_counter > 0)
            _currentAddress = _loopAddress;
        break;
    case Interpreter::FIN:
        _led.turnOff();
        _wheels.stop();
        _music.stopNote();
        break;

    default:
        break;
    }
}
