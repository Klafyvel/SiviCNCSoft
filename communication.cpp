#include "communication.h"

void derror(char* error)
{
	Serial.print("Error");
	Serial.println(error);
}

#ifdef DEBUG
void dinfo(char* info)
{
	Serial.println(info);
}

void dchar(char c)
{
	Serial.println(c);
}
#else
void dinfo(char* info) {}
void dchar(char c) {}
#endif