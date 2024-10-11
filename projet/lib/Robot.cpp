#include "Robot.h"

Robot::Robot() : _button1(0), _button2(1), _led(&PORTC, &DDRC, PC2, PC3), desiredDistance(_position.getDesiredDistance()), turnRightCounter(_wheels.turnRightCounter), turnLeftCounter(_wheels.turnLeftCounter)
{
}

void Robot::interruptResetButton1()
{
    _button1.interruptReset();
}

void Robot::interruptAnyEdgeButton1()
{
    _button1.interruptAnyEdge();
}

void Robot::interruptRisingEdgeButton1()
{
    _button1.interruptRisingEdge();
}

void Robot::interruptFallingEdgeButton1()
{
    _button1.interruptFallingEdge();
}

void Robot::interruptEnableButton1()
{
    _button1.interruptEnable();
}

void Robot::interruptDisableButton1()
{
    _button1.interruptDisable();
}

void Robot::interruptResetButton2()
{
    _button2.interruptReset();
}

void Robot::interruptAnyEdgeButton2()
{
    _button2.interruptAnyEdge();
}

void Robot::interruptRisingEdgeButton2()
{
    _button2.interruptRisingEdge();
}

void Robot::interruptFallingEdgeButton2()
{
    _button2.interruptFallingEdge();
}

void Robot::interruptEnableButton2()
{
    _button2.interruptEnable();
}

void Robot::interruptDisableButton2()
{
    _button2.interruptDisable();
}

uint8_t Robot::readDistance()
{
    uint8_t distanceRead = _distanceSensor.readDistance();
    return distanceRead;
}
bool Robot::isWallDetected()
{
    return _distanceSensor.isWallDetected();
}

void Robot::turnOnLedRed()
{
    _led.turnOnRed();
}

void Robot::turnOnLedGreen()
{
    _led.turnOnGreen();
}

void Robot::turnOffLed()
{
    _led.turnOff();
}
void Robot::followLine()
{
    _line.followLine();
}
void Robot::playNote(uint8_t note)
{
    _music.playNote(note);
}

void Robot::stopNote()
{
    _music.stopNote();
}

void Robot::moveForward(uint8_t leftPercentage, uint8_t rightPercentage)
{
    _wheels.moveForward(leftPercentage, rightPercentage);
}

void Robot::stopMotors()
{
    _wheels.stop();
}

void Robot::moveBackwards(uint8_t leftPercentage, uint8_t rightPercentage)
{
    _wheels.moveBackwards(leftPercentage, rightPercentage);
}

void Robot::turnRight()
{
    _wheels.turnRight();
    turnRightCounter = _wheels.turnRightCounter;
}

void Robot::turnLeft()
{
    _wheels.turnLeft();
    turnLeftCounter = _wheels.turnLeftCounter;
}

void Robot::stopRobot()
{
    _led.turnOff();
    _wheels.stop();
    _music.stopNote();
}

void Robot::moveToCenter()
{
    _position.moveToCenter();
}

void Robot::faceExit()
{
    _position.faceExit();
    turnRightCounter = _position.turnRightCounter;
}

void Robot::startTimer1(uint16_t durationMs, uint16_t start)
{
    _timer1.startTimer1(durationMs, start);
}

void Robot::transmit(char data)
{
    _rs232.transmit(data);
}

void Robot::transmit(const char *data)
{
    _rs232.transmit(data);
}

uint8_t Robot::receive()
{
    return _rs232.receive();
}

void Robot::transmitMessage(const char message[])
{
    _rs232.transmitMessage(message);
}

void Robot::transmitMessageValue(const char message[], uint8_t value)
{
    _rs232.transmitMessageValue(message, value);
}

void Robot::transmitMap()
{
    isTransmittingMap = true;
    _map.transmitMap();
    isTransmittingMap = false;
}