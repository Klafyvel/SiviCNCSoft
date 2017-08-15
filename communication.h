#ifndef H_COMMUNICATION
#define H_COMMUNICATION

#include "settings.h" 
// #include "Arduino.h"

// void error(char* msg) {
// 	Serial.print("Error :");
// 	Serial.println(msg);
// };

// void msg(char* msg) {
// 	Serial.println(msg);
// };

#ifdef DEBUG
#define dvar(var) Serial.print(#var);Serial.print(" : ");Serial.println(var)
#define dvarbin(var) Serial.print(#var);Serial.print(" : ");Serial.println(var, BIN)
#define dinfo(info) Serial.println(info)
#else
#define dvar(var)
#define dinfo(info)
#endif

#endif