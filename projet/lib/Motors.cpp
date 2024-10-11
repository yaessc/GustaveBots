#include "Motors.h"
Motors::Motors()
{
    DDRB |= LEFT_WHEEL | LEFT_DIRECTION | RIGHT_WHEEL | RIGHT_DIRECTION;
    TCCR0A |= (1 << COM0A1) | (1 << COM0B1) | (1 << WGM00);
    TCCR0B |= (1 << CS01);
}

void Motors::adjustMotorSpeed(uint8_t leftWheelPercentage, uint8_t rightWheelPercentage)
{
    OCR0A = (MAX_SPEED * rightWheelPercentage) / ONE_HUNDRED;
    OCR0B = (MAX_SPEED * leftWheelPercentage) / ONE_HUNDRED;
}

void Motors::moveForward(uint8_t leftWheelPercentage, uint8_t rightWheelPercentage)
{
    PORTB &= ~LEFT_DIRECTION;
    PORTB &= ~RIGHT_DIRECTION;
    adjustMotorSpeed(leftWheelPercentage, rightWheelPercentage);
}

void Motors::moveBackwards(uint8_t leftWheelPercentage, uint8_t rightWheelPercentage)
{
    PORTB |= LEFT_DIRECTION | RIGHT_DIRECTION;
    adjustMotorSpeed(leftWheelPercentage, rightWheelPercentage);
}
void Motors::stop()
{
    PORTB &= ~LEFT_WHEEL;
    PORTB &= ~LEFT_DIRECTION;
    PORTB &= ~RIGHT_WHEEL;
    PORTB &= ~RIGHT_DIRECTION;
    adjustMotorSpeed(STOPPED_SPEED, STOPPED_SPEED);
}

void Motors::turnLeft()
{
    PORTB |= LEFT_DIRECTION;
    PORTB &= ~RIGHT_DIRECTION;
    adjustMotorSpeed(67, 67);
    turnLeftCounter++;
}

void Motors::turnRight()
{
    PORTB &= ~LEFT_DIRECTION;
    PORTB |= RIGHT_DIRECTION;
    adjustMotorSpeed(67, 67);
    turnRightCounter++;
}