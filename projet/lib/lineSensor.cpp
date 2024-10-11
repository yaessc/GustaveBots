
#include "lineSensor.h"

LineSensor::LineSensor()
{
}
void LineSensor::writeSegmentsIntoMemory()
{
	uint16_t currentAddress = 0;

	for (uint8_t i = 0; i < 6; i++)
	{
		_memory.ecriture(currentAddress++, _segmentsInfo[i][0]);
		_delay_ms(5);
		_memory.ecriture(currentAddress++, _segmentsInfo[i][1]);
		_delay_ms(5);
		_memory.ecriture(currentAddress++, _segmentsInfo[i][2]);
		_delay_ms(5);
	}
}

bool LineSensor::readSensor(Sensor sensor)
{
	switch (sensor)
	{
	case Sensor::S1:
		return (PINA & (1 << PA0));
		break;

	case Sensor::S2:
		return (PINA & (1 << PA1));
		break;

	case Sensor::S3:
		return (PINA & (1 << PA2));
		break;

	case Sensor::S4:
		return (PINA & (1 << PA3));
		break;

	case Sensor::S5:
		return (PINA & (1 << PA4));
	default:
		return false;
	}
}

void LineSensor::stayStraight()
{

	if (readSensor(Sensor::S5))
	{
		_wheels.moveForward(78, 30);
	}
	else if (readSensor(Sensor::S1))
	{
		_wheels.moveForward(38, 70);
	}
	else if (readSensor(Sensor::S4))
	{
		_wheels.moveForward(78, 50);
	}
	else if (readSensor(Sensor::S2))
	{
		_wheels.moveForward(58, 70);
	}
	else if (readSensor(Sensor::S3))
	{
		_wheels.moveForward(58, 50);
	}
}

void LineSensor::turnCorner()
{

	_wheels.moveForward(60, 50);
	_delay_ms(1700);
	_wheels.moveBackwards(58, 50);
	_delay_ms(100);
	_wheels.stop();
	_delay_ms(390);
	_wheels.turnRight();
	_delay_ms(700);

	_chronometer.RestartChrono();

	while (true)
	{
		_wheels.turnRight();

		uint16_t elapsedTime = _chronometer.getCurrentTime();

		if (elapsedTime > 35)
		{
			_currentSegment += 1;
			while (!readSensor(Sensor::S1))
			{
				_wheels.turnLeft();
			}
			_wheels.turnRight();
			_delay_ms(250);
			_wheels.stop();
			if (_orientation > 1)
				_segmentsInfo[_currentSegment][0] = 2;
			else
				_segmentsInfo[_currentSegment][0] = 1;
			_segmentsInfo[_currentSegment][1] = 1;
			break;
		}
		if (readSensor(Sensor::S4))
		{
			_wheels.turnLeft();
			_delay_ms(250);
			if (_orientation > 1)
				_segmentsInfo[_currentSegment][0] = 2;
			else
				_segmentsInfo[_currentSegment][0] = 1;
			break;
		}
	}

	_wheels.stop();
}

void LineSensor::turnCornerLeft()
{
	_wheels.moveForward(58, 50);
	_delay_ms(1600);
	_wheels.stop();
	_delay_ms(390);
	_wheels.turnLeft();
	_delay_ms(200);
	_wheels.moveBackwards(58, 50);
	_delay_ms(300);
	_wheels.turnLeft();
	_delay_ms(438);

	while (!readSensor(Sensor::S3))
	{
		_wheels.turnLeft();
	}
	_wheels.turnRight();
	_delay_ms(250);
	_wheels.stop();
	while (true)
	{
		stayStraight();
		if (!readSensor(Sensor::S1) && !readSensor(Sensor::S2) && !readSensor(Sensor::S3) && !readSensor(Sensor::S4) && !readSensor(Sensor::S5))
		{
			_wheels.stop();
			break;
		}
	}
}

void LineSensor::stayStraightBackwards()
{
	if (readSensor(Sensor::S5))
	{
		_wheels.moveBackwards(30, 65);
	}
	else if (readSensor(Sensor::S1))
	{
		_wheels.moveBackwards(68, 38);
	}
	else if (readSensor(Sensor::S4))
	{
		_wheels.moveBackwards(50, 65);
	}
	else if (readSensor(Sensor::S2))
	{
		_wheels.moveBackwards(68, 58);
	}
	else if (readSensor(Sensor::S3))
	{
		_wheels.moveBackwards(58, 50);
	}
}

void LineSensor::goBackToMain()
{
	_chronometer.RestartChrono();
	_wheels.moveBackwards(58, 50);
	_delay_ms(500); 
	while (true)
	{
		stayStraightBackwards();
		if (readSensor(Sensor::S1) && readSensor(Sensor::S2) && readSensor(Sensor::S3) && readSensor(Sensor::S4) && readSensor(Sensor::S5))
		{
			if (_chronometer.getCurrentTime() < 120){
				_segmentsInfo[_currentSegment][1] = 2;
				}
			else{
				_segmentsInfo[_currentSegment][1] = 3;
				}
			break;
		}
	}
	_wheels.moveForward(58, 50);
	_wheels.stop();
	_delay_ms(100);
	_wheels.moveForward(58, 54);
	_delay_ms(2200);
	_wheels.moveBackwards(58, 50);
	_delay_ms(100);
	_wheels.turnLeft();
	_delay_ms(540);
	while (!readSensor(Sensor::S1))
	{
		_wheels.turnLeft();
	}
	_wheels.turnRight();
	_delay_ms(250);
	_wheels.stop();
}

void LineSensor::followLine()
{
	bool onMain = true;
	bool ending = false;

	while (true)
	{
		if (readSensor(Sensor::S3) && readSensor(Sensor::S5) && onMain)
		{
			_tempPosition = _chronometer.getCurrentTime();

			turnCorner();
			_orientation += 1;
		}
		if (readSensor(Sensor::S3) && readSensor(Sensor::S1) && onMain)
		{
			onMain = false;
			ending = true;
			turnCornerLeft();
			break;
		}
		if (!readSensor(Sensor::S1) && !readSensor(Sensor::S2) && !readSensor(Sensor::S3) && !readSensor(Sensor::S4) && !readSensor(Sensor::S5) && !ending)
		{
			onMain = false;
			_segmentsInfo[_currentSegment][2] = _tempPosition + 50;
			_currentSegment += 1;
			_orientation -= 1;
			goBackToMain();
			onMain = true;
		}
		else if (onMain)
		{
			_chronometer.RestartChrono();

			stayStraight();
		}
	}
	writeSegmentsIntoMemory();
}