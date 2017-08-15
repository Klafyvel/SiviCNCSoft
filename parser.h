#ifndef H_PARSER
#define H_PARSER

#include "Arduino.h"

#include "settings.h"

#include "stack.h"
#include "queue.h"

#include "communication.h"
#include "codeVar.h"


class Parser
{
public:
  Parser();
  ~Parser() {}

  bool parse(char car);
  
  void flush();

  bool isSet(uint8_t var) const;
  float getVar(uint8_t var) const;
  bool commandOver() const;
  
private:
  float parseNum();
  bool parseWord();

  bool setVar[NB_VAR];
  float var[NB_VAR];
  bool endOfLine;
  Queue<char> word;
};


#endif