#ifndef H_MOVEMENT_MANAGER
#define H_MOVEMENT_MANAGER

#include "settings.h"
#include "axis.h"


class MovementManager
{
public:
	MovementManager();

	Axis axis_x;
	Axis axis_y;
	Axis axis_z;

private:
	unsigned long timeStep;
	unsigned long lastTime;

};

#endif