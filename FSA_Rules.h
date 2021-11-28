#ifndef CS236_PROJECT1_FSA_RULES_H
#define CS236_PROJECT1_FSA_RULES_H


#include "Automaton.h"
#include <string>

class FSA_Rules : public Automaton
{
private:
    void S1(const std::string& input){
        if (input[index] == 'u'){
            inputRead++;
            index++;
            S2(input);
        }
        else{ Serr();}
    }
    void S2(const std::string& input){
        if (input[index] == 'l'){
            inputRead++;
            index++;
            S3(input);
        }
        else{ Serr();}
    }
    void S3(const std::string& input){
        if (input[index] == 'e'){
            inputRead++;
            index++;
            S4(input);
        }
        else{ Serr();}
    }
    void S4(const std::string& input){
        if (input[index] == 's'){
            inputRead++;
            //Go to an accept state
        }
        else{ Serr();}
    }
public:
    FSA_Rules() : Automaton(TokenType:: RULES) {}


    void S0(const std::string& input){
        if (input[index] == 'R'){
            inputRead++;
            index++;
            S1(input);
        }
        else{
            Serr();
        }
    }

};

#endif //CS236_PROJECT1_FSA_RULES_H
