#ifndef CS236_PROJECT1_FSA_ID_H
#define CS236_PROJECT1_FSA_ID_H


#include "Automaton.h"


class FSA_ID : public Automaton
{
private:
    void S1 (const std::string& input){
//        char a = input[index];
        if(isalnum(input[index])){
            //For each successive alphanumeric we add it and go to the next
            inputRead++;
            index++;
            S1(input);
        }else {
            SF(input);// Go into the final state if we get the next thing and it's not alphanumer*ic
            //I'm pretty sure we keep on pulling in. And everything else is an error
        }

    }
    void SF(const std::string& input){
        //This is the accept state and is really just here for my visual pleasure.
    }
public:
    FSA_ID() : Automaton(TokenType:: ID) {}


    void S0  (const std::string& input){
//        char a = input[index];
        if(isalpha(input[index])){
            index++;
            inputRead++;
            S1(input);
        }

    }


};


#endif //CS236_PROJECT1_FSA_ID_H
