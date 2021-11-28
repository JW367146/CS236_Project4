#ifndef CS236_PROJECT1_FSA_R_PAREN_H
#define CS236_PROJECT1_FSA_R_PAREN_H


#include "Automaton.h"




class FSA_R_Paren : public Automaton
{
public:
    FSA_R_Paren() : Automaton(TokenType::RIGHT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (input[index] == ')') {
            inputRead = 1;
        } else {
            Serr();
        }
    }
};




#endif //CS236_PROJECT1_FSA_R_PAREN_H
