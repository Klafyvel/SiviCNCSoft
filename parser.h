// #ifndef H_DFA
// #define H_DFA

// // #include <iostream>

// #include "settings.h"

// #include "stack.h"
// #include "queue.h"

// #include "communication.h"
// #include "codeVar.h"

// namespace parser
// {
//   class Parser
//   {
//   public:
//     Parser();
//     ~Parser() {}

//     float parseNum(Queue<char>* num) const;
//     bool parseWord(Queue<char>* word);
//     void parse(char car);
    
//     void flush();

//     bool isSet(uint8_t var) const;
//     float getVar(uint8_t var) const;
//     bool commandOver() const;
    
//   private:
//     bool setVar[NB_VAR];
//     float var[NB_VAR];
//     bool endOfLine;
//   };
// }


// #endif