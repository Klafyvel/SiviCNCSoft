#include "stepper.h"

Stepper::Stepper(uint8_t IN1, uint8_t IN2, uint8_t IN3, uint8_t IN4, 
	DriveMode drive)
{
	this->IN1 = IN1;
	this->IN2 = IN2;
	this->IN3 = IN3;
	this->IN4 = IN4;

	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);

	this->mode = drive;

	this->currentState = 0;

	Stepper::setOutput();
}

void Stepper::step(Direction direction)
{
	uint8_t m = 0;
	switch(this->mode)
	{
		case DRIVE_NORMAL: m = DRIVE_NORMAL_NB_STEP; break;
		case DRIVE_FULL: m = DRIVE_FULL_NB_STEP; break;
		case DRIVE_HALF: m = DRIVE_HALF_NB_STEP; break;
		default : break;
	}
	this->currentState = (this->currentState + 1) % m;
	this->dir = direction;
	this->setOutput();
}

void Stepper::pause()
{
	this->currentState = 0;
	digitalWrite(this->IN1, 0);
	digitalWrite(this->IN2, 0);
	digitalWrite(this->IN3, 0);
	digitalWrite(this->IN4, 0);

}

void Stepper::setOutput()
{
	uint8_t b = 0;
	switch(this->mode)
	{
		case DRIVE_NORMAL : 
			if(this->dir == FORWARD)
				b = DRIVE_NORMAL_STEP[this->currentState]; 
			else
				b = DRIVE_NORMAL_STEP_REVERSE[this->currentState];
			break;
		case DRIVE_FULL : b = DRIVE_FULL_STEP[this->currentState]; break;
		case DRIVE_HALF : b = DRIVE_NORMAL_STEP[this->currentState]; break;
		default: break;
	}
	digitalWrite(this->IN1, getB1(b));
	digitalWrite(this->IN2, getB2(b));
	digitalWrite(this->IN3, getB3(b));
	digitalWrite(this->IN4, getB4(b));
}