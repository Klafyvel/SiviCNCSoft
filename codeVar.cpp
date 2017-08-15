#include "codeVar.h"

uint8_t commandOfChar(char c) 
{
  switch (c) {
    case 'G' : return CODE_G;
    case 'M' : return CODE_M;
    case 'S' : return CODE_S;
    case 'F' : return CODE_F;
    case 'X' : return CODE_X;
    case 'Y' : return CODE_Y;
    case 'Z' : return CODE_Z;
    case 'I' : return CODE_I;
    case 'J' : return CODE_J;
    case 'K' : return CODE_K;
    default : return CODE_UNKNW;
  }
}

char charOfCommand(uint8_t command) 
{
  switch (command) {
    case CODE_G : return 'G';
    case CODE_M : return 'M';
    case CODE_S : return 'S';
    case CODE_F : return 'F';
    case CODE_X : return 'X';
    case CODE_Y : return 'Y';
    case CODE_Z : return 'Z';
    case CODE_I : return 'I';
    case CODE_J : return 'J';
    case CODE_K : return 'K';
    default : return 'U';
  }
}