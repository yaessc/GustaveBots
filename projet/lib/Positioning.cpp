#include "Positioning.h"

Positioning::Positioning()
{
}

void Positioning::moveToCenter()
{

    while (true)
    {
        uint8_t distanceFromWall = _distance.readDistance();

        if (distanceFromWall > _desiredDistance)
        {
            _wheels.moveBackwards(57, 50);
        }
        else if (distanceFromWall < _desiredDistance)
        {
            _wheels.moveForward(57, 50);
        }
        else if (distanceFromWall == _desiredDistance)
        {
            _wheels.stop();
            _delay_ms(400);
            break;
        }
    }
}   

void Positioning::faceExit()
{
    _wheels.turnRight();
    _delay_ms(800);
    _wheels.stop();
    turnRightCounter++;

    _delay_ms(500);
    uint8_t distanceFromWall = _distance.readDistance();
    if (distanceFromWall > 20)
    {
        _wheels.turnRight();
        _delay_ms(800);
        _wheels.stop();
        turnRightCounter++;
        _delay_ms(500);
        _wheels.turnRight();
        _delay_ms(800);
        _wheels.stop();
        turnRightCounter++;
    }
}

uint8_t Positioning::getDesiredDistance()
{
    return _desiredDistance;
}