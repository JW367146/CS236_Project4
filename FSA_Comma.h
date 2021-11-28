#ifndef CS236_PROJECT1_FSA_COMMA_H
#define CS236_PROJECT1_FSA_COMMA_H



#include "Automaton.h"

class FSA_Comma : public Automaton
{
public:
    FSA_Comma() : Automaton(TokenType::COMMA) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (input[index] == ',') {
            inputRead = 1;
        } else {
            Serr();
        }
    }
};

#endif //CS236_PROJECT1_FSA_COMMA_H
