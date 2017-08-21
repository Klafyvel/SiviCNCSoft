#ifndef H_AXIS
#define H_AXIS

#include "settings.h"
#include "communication.h"

#include "stepper.h"

#include <math.h>

#define sign(a) ((a>0)?1:((a<0)?-1:0))
#define dir(a) ((a>0)?FORWARD:BACKWARD)

enum Movement
{
	MOVEMENT_CONTINUOUS,
	MOVEMENT_STEP,
	MOVEMENT_MM,
	MOVEMENT_NONE
};

class Axis
{
public:
	Axis();

	void registerMovement(float mm, float mmStep);
	void startContinuous(Direction dir);
	void registerMovementStep(int steps);
	void stop();
	bool move();
	bool collide();
	Direction getCurrentDirection() const {return this->currentDirection;}

	Stepper stepper;
	float ratio; // step/mm
	float play; // mm
	bool reversed;
	unsigned long minTime; // ms
	unsigned long time;
	uint8_t endStop1;
	uint8_t endStop2;

private:
	void moveMm();
	void moveStep();

	int nbStep;
	int step;
	float mm;
	float mmStep;
	float remainStep;

	Direction lastDirection;
	Direction currentDirection;

	float remains; // steps;

	Movement currentMovement;

	unsigned long timer;

};

#endif