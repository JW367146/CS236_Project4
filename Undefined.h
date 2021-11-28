
#ifndef CS236_PROJECT1_UNDEFINED_H
#define CS236_PROJECT1_UNDEFINED_H


#include "Automaton.h"
#include <string>

class Undefined : public Automaton
{
private:


public:
    //I need this class to make an undefined automon to make a token.
    Undefined() : Automaton(TokenType:: UNDEFINED) {}


    void S0(const std::string& input){

    }



};

#endif //CS236_PROJECT1_UNDEFINED_H
