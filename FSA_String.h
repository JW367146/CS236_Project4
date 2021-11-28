#ifndef CS236_PROJECT1_FSA_STRING_H
#define CS236_PROJECT1_FSA_STRING_H



#include "Automaton.h"

class FSA_String : public Automaton
{

private:

    void S1 (const std::string& input){
        //char a = input[index];

        //I need to change this so that '''' is only one string aparently
        if(input[index] == '\''){
            inputRead++;
            index++;
            //go to accept state

            //maybe I shouldn't go to an accept state yet. I should go to that same place in s3?
            S3(input);
        }

        //Now check to see if we reached the end of file
        else if(EndofFile(input,inputRead+1)){
            StringSerr();
        }
        else if(input[index]){
            if (input[index] =='\n'){
                newLines++;
            }
            inputRead++;
            index++;
            S2(input);
        }else {
            Serr();
        }
        //Now if we have something at input[index] we want it in our string


    }
    void S2 (const std::string& input){
        //char a = input[index];
        if(EndofFile(input,inputRead+1)){
            StringSerr();
        }
        else if(input[index] == '\''){
            inputRead++;
            index++;
            S3(input);
        }
        else if(input[index]){
            if (input[index] =='\n'){
                newLines++;
            }

            //If it not is not ' or a new line then it is just another char in the string and we can accept any char
            inputRead++;
            index++;
            S2(input);

        }
        else{
            Serr();
        }

    }

    void S3 (const std::string& input){
       // char a = input[index];
        if(input[index] == '\''){
            // This means there is a ''inside the string which shouldn't terminate the string
            inputRead++;
            index++;
            S2(input);
        }
        else if(input[index] == '\n'){
            //If we got here and there's a new line then our string is done

            //We go to an accept state
            //We shouldn't increment input read
        }
        else{
            //If we got to this stage, then we got ' and then another' and unless there is a ' coming right after our string is done.
            //inputRead++;

            //Go to accept state
            // We shouldn't increment input read here.
        }
    }

public:
    FSA_String() : Automaton(TokenType::STRING) {}  // Call the base constructor

    void S0(const std::string& input) {
      // char a = input[index];
        if (input[index] == '\'') {
            index++;
            inputRead++;
            S1(input);
        } else {Serr();}
    }
};



#endif //CS236_PROJECT1_FSA_STRING_H
