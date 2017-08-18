#include "axis.h"

Axis::Axis()
{
	this->stepper = Stepper();
	this->ratio = 1;
	this->play = 0;
	this->reversed = false;
	this->minTime = 0;
	this->nbStep = 0;
	this->step = 0;
	this->mm = 0;
	this->mmStep = 0;
	this->remainStep = 0;
	this->lastDirection = FORWARD;
	this->currentDirection = FORWARD;
	this->remains = 0;
	this->currentMovement = MOVEMENT_NONE;
}

void Axis::registerMovement(float mm, float mmStep)
{
	this->currentMovement = MOVEMENT_MM;
	this->stepper.pause();
	this->step = abs(mmStep) / ratio;
	this->nbStep = abs(mm) / ratio;
	this->mm = abs(mm);
	this->mmStep = abs(mmStep);
	this->remainStep = modf(mmStep / this->ratio, NULL);
	this->currentDirection = ((mm >= 0)==!this->reversed)?FORWARD:BACKWARD;

	if(this->currentDirection != this->lastDirection)
	{
		double n;
		this->remains += modf(this->play/this->ratio, &n);
		for (int i = 0; i < n; ++i)
			this->stepper.step(this->currentDirection);
		this->lastDirection = currentDirection;
	}
}

void Axis::startContinuous(Direction dir)
{
	this->currentMovement = MOVEMENT_CONTINUOUS;
	this->currentDirection = this->reversed?dir:-dir;
	this->lastDirection = this->reversed?dir:-dir;
	this->nbStep = 1;
}

void Axis::registerMovementStep(int steps)
{
	this->stepper.pause();
	this->currentMovement = MOVEMENT_STEP;
	this->nbStep = abs(steps);
	this->currentDirection = this->reversed?dir(steps):-dir(steps);
	this->lastDirection = this->reversed?dir(steps):-dir(steps);
}

void Axis::stop()
{
	this->nbStep = 0;
	this->stepper.pause();
	this->step = 0;
	this->currentMovement = MOVEMENT_NONE;
}

bool Axis::move()
{
	if( (millis() - this->timer < this->minTime))
		return true;

	this->timer = millis();

	if((this->nbStep <= 0 ) || (this->currentMovement==MOVEMENT_NONE))
	{
		this->stepper.pause();
		return true;
	}
	else if (this->currentMovement == MOVEMENT_CONTINUOUS)
	{
		this->stepper.step(this->currentDirection);
		return true;
	}
	else if (this->currentMovement == MOVEMENT_STEP)
		Axis::moveStep();
	else
		Axis::moveMm();

	return this->nbStep == 0;
}

void Axis::moveMm()
{
	for (int i = 0; i < this->step; ++i)
	{
		this->stepper.step(this->currentDirection);
		if(i < this->step-1)
			delay(this->minTime);
	}
	this->remains += this->remainStep;
	this->nbStep -= this->step;

	if(this->nbStep <= 0)
	{
		this->remains += this->nbStep;
		this->nbStep = 0;
	}

	if (abs(this->remains) > 1)
	{
		Direction dir = ((this->remains >= 0)==!this->reversed)?FORWARD:BACKWARD;
		int n = (int)(abs(this->remains));
		this->remains = (abs(this->remains) - n)*((this->remains>=0)?1:-1);
		for (int i = 0; i < n; ++i)
		{
			this->stepper.step(dir);
			if(i < n-1)
				delay(this->minTime);
		}
	}
}

void Axis::moveStep()
{
	for (int i = 0; i < this->nbStep; ++i)
	{
		this->stepper.step(this->currentDirection);
		delay(this->minTime);
	}
	this->nbStep = 0;
}