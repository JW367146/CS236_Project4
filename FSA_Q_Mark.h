
#ifndef CS236_PROJECT1_FSA_Q_MARK_H
#define CS236_PROJECT1_FSA_Q_MARK_H

#include "Automaton.h"

class FSA_Q_Mark : public Automaton
{
public:
    FSA_Q_Mark() : Automaton(TokenType::Q_MARK) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (input[index] == '?') {
            inputRead = 1;
        } else {
            Serr();
        }
    }
};




#endif //CS236_PROJECT1_FSA_Q_MARK_H
