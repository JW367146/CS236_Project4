#ifndef CS236_PROJECT1_FSA_MULTIPLY_H
#define CS236_PROJECT1_FSA_MULTIPLY_H



#include "Automaton.h"

class FSA_Multiply : public Automaton
{
public:
    FSA_Multiply() : Automaton(TokenType::MULTIPLY) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (input[index] == '*') {
            inputRead = 1;
        } else {
            Serr();
        }
    }
};



#endif //CS236_PROJECT1_FSA_MULTIPLY_H
