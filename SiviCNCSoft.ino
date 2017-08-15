#include "axis.h"
#include "stepper.h"

Axis a = Axis();

void setup()
{
  Serial.begin(9600);
  a.stepper = Stepper(6,7,8,9, DRIVE_FULL);
  a.minTime = 10;
}

void loop()
{
  if(Serial.available())
  {
    a.registerMovement(-300, 30);
  }
  bool b = a.move();
  delay(a.minTime);

  if(b)
  {
    Serial.println("ok");
  }
}
