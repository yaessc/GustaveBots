#include "DistanceSensor.h"
DistanceSensor::DistanceSensor()
{
    DDRA &= ~(1 << PA0);
}
uint8_t DistanceSensor::readDistance()
{
    uint8_t reading = (_converter.lecture(0) >> 2);
    return reading;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
bool DistanceSensor::isWallDetected() {

    uint8_t distance = readDistance();
    return distance >= _MIN_DETECTED_DISTANCE && distance <= _MAX_DETECTED_DISTANCE;
}