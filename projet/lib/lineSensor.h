/*
 * Description: Classe permettant la lecture du suiveur de ligne et de faire bouger le robot en conséquence.
 * Identifications matérielles : Suiveur de ligne D1 sur PA0, D2 sur PA1, D3 sur PA2, D4 sur PA3, D5 sur PA4                           
 */

/*
 * Description: Class enabling the line follower to be read and the robot to be moved accordingly.
 * Hardware identifications: Line follower D1 on PA0, D2 on PA1, D3 on PA2, D4 on PA3, D5 on PA4                           
 */
#pragma once
#include "Chrono.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "memoire_24.h"
#include "Motors.h"

enum Sensor
{
	S1,
	S2,
	S3,
	S4,
	S5
};

class LineSensor
{

public:
	LineSensor();
	void followLine();

private:
	Motors _wheels;
	Chrono _chronometer;
	uint8_t _segmentsInfo[6][3];
	uint8_t _currentSegment = 0;
	uint8_t _orientation = 0;
	uint16_t _tempPosition = 0;
	Memoire24CXXX _memory;
	void writeSegmentsIntoMemory();
	bool readSensor(Sensor sensor);
	void stayStraight();
	void turnCorner();
	void turnCornerLeft();
	void stayStraightBackwards();
	void goBackToMain();
};
