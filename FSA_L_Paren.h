#ifndef CS236_PROJECT1_FSA_L_PAREN_H
#define CS236_PROJECT1_FSA_L_PAREN_H


#include "Automaton.h"

class FSA_L_Paren : public Automaton
{
public:
    FSA_L_Paren() : Automaton(TokenType::LEFT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (input[index] == '(') {
            inputRead = 1;
        } else {
            Serr();
        }
    }
};









#endif //CS236_PROJECT1_FSA_L_PAREN_H
