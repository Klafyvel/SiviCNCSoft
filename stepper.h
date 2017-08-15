#ifndef H_STEPPER
#define H_STEPPER

#include "Arduino.h"
#include "communication.h"

#define getB1(b) (b & 0b1000) >> 3
#define getB2(b) (b & 0b0100) >> 2
#define getB3(b) (b & 0b0010) >> 1
#define getB4(b) (b & 0b0001)


enum DriveMode
{
	DRIVE_NORMAL,
	DRIVE_FULL,
	DRIVE_HALF,
	DRIVE_DISABLED
};

enum Direction
{
	FORWARD = 1,
	BACKWARD = -1,
};

const uint8_t DRIVE_NORMAL_NB_STEP = 4;
const uint8_t DRIVE_NORMAL_STEP[4] = {
	0b1000,
	0b0001,
	0b0100,
	0b0010
};

const uint8_t DRIVE_FULL_NB_STEP = 4;
const uint8_t DRIVE_FULL_STEP[4] = {
	0b1010,
	0b0110,
	0b0101,
	0b1001
};

const uint8_t DRIVE_HALF_NB_STEP = 8;
const uint8_t DRIVE_HALF_STEP[8] = {
	0b1000,
	0b1010,
	0b0010,
	0b0110,
	0b0100,
	0b0101,
	0b0001,
	0b1001
};

class Stepper 
{
public:
	Stepper() {};
	Stepper(uint8_t IN1, uint8_t IN2, uint8_t IN3, uint8_t IN4, DriveMode drive=DRIVE_NORMAL);
	void step(Direction direction);
	void pause();

	DriveMode mode;

private:
	void setOutput();

	uint8_t IN1;
	uint8_t IN2;
	uint8_t IN3;
	uint8_t IN4;

	uint8_t currentState;
};

#endif