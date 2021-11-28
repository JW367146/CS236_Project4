
#ifndef CS236_PROJECT1_FSA_ADD_H
#define CS236_PROJECT1_FSA_ADD_H



#include "Automaton.h"

class FSA_Add : public Automaton
{
public:
    FSA_Add() : Automaton(TokenType::ADD) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (input[index] == '+') {
            inputRead = 1;
        } else {
            Serr();
        }
    }
};



#endif //CS236_PROJECT1_FSA_ADD_H
