#include "parser.h"

Parser::Parser() {
  this->endOfLine = false;
  for (int i = 0; i < NB_VAR; ++i)
  {
    this->setVar[i] = false;
    this->var[i] = 0.0;
  }
}

bool Parser::parseWord() {
  dinfo("Parsing word.");

  while(!(this->word.empty()) && (this->word.peek() == ' '))
    this->word.pop();

  char c = this->word.peek();
  uint8_t command = commandOfChar(this->word.pop());

  dvar(charOfCommand(command));

  if (command == CODE_UNKNW)
    return false;

  float arg = Parser::parseNum();
  if(this->setVar[command])
  {
    printError("Already defined");
    return false;
  }
  this->setVar[command] = true;
  this->var[command] = arg;

  dinfo("Done parsing var.");
  return true;
}

float Parser::parseNum(){
  dinfo("parsing number");
  Queue<float> decimals = Queue<float>();
  Stack<float> integers = Stack<float>();
  float res = 0;
  bool currentIsDecimals = false;
  bool negative = false;

  while(!(this->word.empty()) && (this->word.peek() != ' ') && (this->word.peek() != '\n')) 
  {
    char currentChar = this->word.pop();
    float n = 0;
    bool changed = false;
    switch(currentChar) {
      case '-' : negative=true; break;
      case '0' : n = 0; break;
      case '1' : n = 1; break;
      case '2' : n = 2; break;
      case '3' : n = 3; break;
      case '4' : n = 4; break;
      case '5' : n = 5; break;
      case '6' : n = 6; break;
      case '7' : n = 7; break;
      case '8' : n = 8; break;
      case '9' : n = 9; break;
      case '.' : changed = true; break;
      default : break;
    }
    if(changed) {
      currentIsDecimals = true;
    }
    else if (currentIsDecimals)
      decimals.push(n);
    else 
    {
      integers.push(n);
    }
  }
  dinfo("Begin sum.");
  float k = 1;
  while(!integers.empty()) {
    dinfo("there are integers");
    res += (k * integers.pop());
    k *= 10;
  }
  dinfo("Done integers.");
  k = 0.1;
  while(!decimals.empty()) {
    res += k * decimals.pop();
    k *= 0.1;
  }
  if(negative)
    res *= -1;
  dinfo("Done number.");
  return res;
}

bool Parser::parse(char car) {
  dinfo("Parsing");
  if ((car == '\n') || (car == ' '))
  {
    if(!Parser::parseWord())
    {
      constError("Parsing error.");
      return false;
    }
    this->word = Queue<char>();
  }
  else 
  {
    dinfo("Adding");
    dvar(car);
    this->word.push(car);
  }
  if (car == '\n')
  {
    this->endOfLine = true;
  }
  return true;
}

void Parser::flush() {
  this->endOfLine = false;
  for (int i = 0; i < NB_VAR; ++i)
  {
    this->setVar[i] = false;
    this->var[i] = 0.0;
  }
}

bool Parser::commandOver() const {
  return this->endOfLine;
}

bool Parser::isSet(const uint8_t var) const {
  return this->setVar[var];
}

float Parser::getVar(const uint8_t var) const {
  return this->var[var];
}