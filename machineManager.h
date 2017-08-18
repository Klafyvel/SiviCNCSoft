#ifndef H_MACHINE_MANAGER
#define H_MACHINE_MANAGER

#include "settings.h"
#include "communication.h"
#include "parser.h"
#include "axis.h"

#ifdef H_MELODY_STATE
#include "melody.h"
#endif

class MachineManager
{
public:
	MachineManager();

	void command(Parser* parser);
	void checkEvent();
	bool move();
	void stop();

	void processSCode(uint8_t sCode, float param, Axis* axis);

private:
	Axis axisX;
	Axis axisY;
	Axis axisZ;
	bool errorXPreviously;
	bool errorYPreviously;
	bool errorZPreviously;
};

#endif