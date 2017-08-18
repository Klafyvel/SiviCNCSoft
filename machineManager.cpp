#include "machineManager.h"

MachineManager::MachineManager()
{
	this->axisX = Axis();
	this->axisY = Axis();
	this->axisZ = Axis();	

  this->axisX.stepper = Stepper(PIN_AXIS_X_1,PIN_AXIS_X_2,PIN_AXIS_X_3,PIN_AXIS_X_4);
  this->axisZ.stepper = Stepper(PIN_AXIS_Y_1,PIN_AXIS_Y_2,PIN_AXIS_Y_3,PIN_AXIS_Y_4);
  this->axisY.stepper = Stepper(PIN_AXIS_Z_1,PIN_AXIS_Z_2,PIN_AXIS_Z_3,PIN_AXIS_Z_4);

	pinMode(PIN_ENDSTOP_X_1, INPUT_PULLUP);
	pinMode(PIN_ENDSTOP_X_2, INPUT_PULLUP);
	pinMode(PIN_ENDSTOP_Y_1, INPUT_PULLUP);
	pinMode(PIN_ENDSTOP_Y_2, INPUT_PULLUP);
	pinMode(PIN_ENDSTOP_Z_1, INPUT_PULLUP);

	this->axisX.endStop1 = PIN_ENDSTOP_X_1;
	this->axisX.endStop2 = PIN_ENDSTOP_X_2;
	this->axisZ.endStop1 = PIN_ENDSTOP_Z_1;
	this->axisZ.endStop2 = PIN_ENDSTOP_Z_2;
	this->axisY.endStop1 = PIN_ENDSTOP_Y_1;
	this->axisY.endStop2 = PIN_ENDSTOP_Y_2;

	this->errorXPreviously = false;
	this->errorYPreviously = false;
	this->errorZPreviously = false;
}

void MachineManager::command(Parser* parser)
{
	if (parser->isSet(CODE_M))
		return;
	else if (parser->isSet(CODE_G))
		return;
	else if (parser->isSet(CODE_S))
	{
		if (parser->isSet(CODE_X))
			MachineManager::processSCode(parser->getVar(CODE_S), parser->getVar(CODE_X), &(this->axisX));
		if (parser->isSet(CODE_Y))
			MachineManager::processSCode(parser->getVar(CODE_S), parser->getVar(CODE_Y), &(this->axisY));
		if (parser->isSet(CODE_Z))
			MachineManager::processSCode(parser->getVar(CODE_S), parser->getVar(CODE_Z), &(this->axisZ));
	}
	else
		return false;
}

void MachineManager::processSCode(uint8_t sCode, float param, Axis* axis)
{
	axis->stop();
	switch(sCode)
	{
    case 0 : axis->registerMovementStep(param); break;
		case 1 : axis->startContinuous(FORWARD); break;
		case 2 : axis->startContinuous(BACKWARD); break;
		case 3 : axis->stop(); break;
		case 5 : axis->stepper.mode = DRIVE_NORMAL; break;
		case 6 : axis->stepper.mode = DRIVE_FULL; break;
		case 7 : axis->stepper.mode = DRIVE_NORMAL; break;
		case 9 : axis->reversed = true; break;
		case 10 : axis->reversed = false; break;
    case 11 : axis->minTime = param; break;
		default: break;
	}

}

bool MachineManager::move()
{
	return this->axisX.move() && this->axisY.move() && this->axisZ.move();
}

void MachineManager::checkEvent()
{
	if(this->axisX.collide() && !this->errorXPreviously)
	{			
		constError("X end stop.");
		this->errorXPreviously = true;
	}
	else
		this->errorXPreviously = this->axisX.collide();

	if(this->axisZ.collide() && !this->errorZPreviously)
	{
		constError("Z end stop.");
		this->errorZPreviously = true;
	}
	else
		this->errorZPreviously = this->axisZ.collide();

	if(this->axisY.collide() && !this->errorYPreviously)
	{
		constError("Y end stop.");
		this->errorYPreviously = true;
	}
	else
		this->errorYPreviously = this->axisY.collide();

}

void MachineManager::stop()
{
	this->axisX.stop();
	this->axisY.stop();
	this->axisZ.stop();
}