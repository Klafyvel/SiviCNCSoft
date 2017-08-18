
#include "parser.h"
#include "codeVar.h"
#include "axis.h"
#include "stepper.h"

#ifdef MELODY_STATE
#include "melody.h"
#endif

Axis x = Axis();
Axis y = Axis();
Axis z = Axis();
Parser p = Parser();
unsigned long lastTime = 0;

unsigned long timer = 0;

void setup()
{
  #ifdef MELODY_STATE
  initMelody();
  startMelody();
  #endif
  Serial.begin(9600);
  Serial.flush();
  x.stepper = Stepper(2,3,4,5);
  x.minTime = 10;
  z.stepper = Stepper(6,7,8,9, DRIVE_FULL);
  z.minTime = 15;
  y.stepper = Stepper(10,11,12,13, DRIVE_FULL);
  y.minTime = 15;
  lastTime = millis();
  timer = millis();
  p.flush();
}

void loop()
{
  if(Serial.available()>0)
  {
  	int c = Serial.read();
  	dinfo("Availabe");

    if(!p.parse((char)c))
      p.flush();
  }
  if(p.commandOver())
  {
  	dinfo("Command over.");
    uint8_t s = 3;
    if(p.isSet(CODE_S))
    {
    	dinfo("S set.");
      s = p.getVar(CODE_S);

    }
    if(p.isSet(CODE_X))
    {
    	dinfo("X set");
      processS(&x, s, p.getVar(CODE_X));
    }
    if(p.isSet(CODE_Y))
    {
    	dinfo("Y set");
      processS(&y, s, p.getVar(CODE_Y));
    }
    if(p.isSet(CODE_Z))
    {
    	dinfo("Z set");
      processS(&z, s, p.getVar(CODE_Z));
    }
    p.flush();
    Serial.flush();
    Serial.println("ok");
    #ifdef MELODY_STATE
    validateMelody();
    #endif
  }

	x.move();
	y.move();
	z.move();

}

void processS(Axis* a, uint8_t s, float s_arg)
{
	a->stop();
	switch(s)
	{
    case 0: a->registerMovementStep(s_arg); break;
		case 1 : a->startContinuous(FORWARD); break;
		case 2 : a->startContinuous(BACKWARD); break;
		case 3 : a->stop(); break;
		case 5 : a->stepper.mode = DRIVE_NORMAL; break;
		case 6 : a->stepper.mode = DRIVE_FULL; break;
		case 7 : a->stepper.mode = DRIVE_NORMAL; break;
		case 9 : a->reversed = true; break;
		case 10 : a->reversed = false; break;
    case 11 : a->minTime = s_arg; break;
		default: break;
	}
}