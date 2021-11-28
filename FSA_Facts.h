#ifndef CS236_PROJECT1_FSA_FACTS_H
#define CS236_PROJECT1_FSA_FACTS_H


#include "Automaton.h"
#include <string>


class FSA_Facts : public Automaton
{
private:
    void S1(const std::string& input){
        if (input[index] == 'a'){
            inputRead++;
            index++;
            S2(input);
        }
        else{ Serr();}
    }
    void S2(const std::string& input){
        if (input[index] == 'c'){
            inputRead++;
            index++;
            S3(input);
        }
        else{ Serr();}
    }
    void S3(const std::string& input){
        if (input[index] == 't'){
            inputRead++;
            index++;
            S4(input);
        }
        else{ Serr();}

    }
    void S4(const std::string& input) {
        if (input[index] == 's') {
            inputRead++;
            //Go to accept state
        } else { Serr(); }
    }

public:
    FSA_Facts() : Automaton(TokenType:: FACTS) {}


    void S0(const std::string& input){
        if (input[index] == 'F'){
            inputRead++;
            index++;
            S1(input);
        }
        else{
            Serr();
        }
    }

};

#endif //CS236_PROJECT1_FSA_FACTS_H
