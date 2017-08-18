#ifndef H_CODE_VAR
#define H_CODE_VAR

#include "Arduino.h"


#define NB_VAR  10

#define CODE_UNKNW -1
// Commands name
#define CODE_G 0
#define CODE_M 1
#define CODE_S 2
#define CODE_F 3

// axis
#define CODE_X 4
#define CODE_Y 5
#define CODE_Z 6

// For circles
#define CODE_I 7
#define CODE_J 8
#define CODE_K 9

uint8_t commandOfChar(char c);

char charOfCommand(uint8_t command);

#endif