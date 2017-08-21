#ifndef H_COMMUNICATION
#define H_COMMUNICATION

#include "Arduino.h"
#include "settings.h" 

#define constError(err) Serial.print("Error : ");Serial.println(F(err))
#define constWarning(warn) Serial.print("Warning : ");Serial.println(F(warn))

#ifdef DEBUG

#define dinfo(info) Serial.println(F(info))
#define dvar(var) Serial.print(#var);Serial.print(F(" : "));Serial.println(var)

#else

#define dinfo(info)
#define dvar(var)

#endif

#endif