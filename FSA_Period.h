#ifndef CS236_PROJECT1_FSA_PERIOD_H
#define CS236_PROJECT1_FSA_PERIOD_H



#include "Automaton.h"

class FSA_Period : public Automaton
{
public:
    FSA_Period() : Automaton(TokenType::PERIOD) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (input[index] == '.') {
            inputRead = 1;
        } else {
            Serr();
        }
    }
};


#endif //CS236_PROJECT1_FSA_PERIOD_H
