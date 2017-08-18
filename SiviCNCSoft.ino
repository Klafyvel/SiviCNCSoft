#include "machineManager.h"

#ifdef MELODY_STATE
#include "melody.h"
#endif

Parser p = Parser();
MachineManager m = MachineManager();

void setup()
{
  #ifdef MELODY_STATE
  initMelody();
  startMelody();
  #endif
  Serial.begin(9600);
  Serial.flush();
  p.flush();

  #ifdef MELODY_STATE
  successMelody();
  #endif
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
    m.command(&p);

	if(m.move() && p.commandOver())
  {
    p.flush();
    Serial.flush();
    Serial.println("ok");
    #ifdef MELODY_STATE
    validateMelody();
    #endif
  }

}