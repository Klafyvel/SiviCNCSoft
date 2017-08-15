// #include "parser.h"

// namespace parser {
//   Parser::Parser() {
//     endOfLine = false;
//     for (int i = 0; i < NB_VAR; ++i)
//     {
//       setVar[i] = false;
//       var[i] = 0.0;
//     }
//   }

//   bool Parser::parseWord(Queue<char>* word) {
//     uint8_t command = commandOfChar(word->pop());
//     if (command == UNKNW)
//       return false
//     float arg = Parser::parseNum(word);
//     if(setVar[command])
//     {
//       error(sprintf("%c already defined.", c));
//       return false
//     }
//     setVar[command] = true;
//     var[command] = arg;
//     return true;
//   }

//   float Parser::parseNum(queue<char>* num) const{
//     Queue<uint8_t> decimals;
//     Stack<uint8_t> integers;
//     float res = 0;
//     bool currentIsDecimals = false;
//     while(! num->empty()) {
//       char currentChar = num->pop();
//       uint8_t n = 0;
//       bool changed = false;
//       switch(currentChar) {
//         case '0' : n = 0; break;
//         case '1' : n = 1; break;
//         case '2' : n = 2; break;
//         case '3' : n = 3; break;
//         case '4' : n = 4; break;
//         case '5' : n = 5; break;
//         case '6' : n = 6; break;
//         case '7' : n = 7; break;
//         case '8' : n = 8; break;
//         case '9' : n = 9; break;
//         case '.' : changed = true; break;
//         default : break;
//       }
//       if(changed) {
//         currentIsDecimals = true;
//       }
//       else if (currentIsDecimals)
//         decimals.push(n);
//       else 
//         integers.push(n);
//     }
//     int k = 1;
//     while(!integers.empty()) {
//       res += k * integers.pop();
//       k *= 10;
//     }
//     float k = 0.1;
//     while(!decimals.empty()) {
//       res += k * decimals.pop();
//       k *= 0.1;
//     }
//     return res;
//   }

//   void Parser::parse(char car) {
//     Queue word = Queue();
//     if (car == '\n' || car == ' ')
//     {
//       if(! parse(*word))
//         error(sprintf("While parsing word before char %d", i))
//       word = Queue();
//     }
//     else 
//       word.push(car);
//     if (car == '\n')
//     {
//       endOfLine = true;
//     }
//   }

//   void Parser::flush() {
//     endOfLine = false;
//     for (int i = 0; i < NB_VAR; ++i)
//     {
//       setVar[i] = false;
//       var[i] = 0.0;
//     }
//   }

//   void Parser::commandOver() const {
//     return endOfLine;
//   }

// }