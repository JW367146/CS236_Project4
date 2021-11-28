#ifndef CS236_PROJECT1_FSA_COMMENT_H
#define CS236_PROJECT1_FSA_COMMENT_H


#include "Automaton.h"


class FSA_Comment : public Automaton
{
private:
    void S1 (const std::string& input){
//        bool b = EndofFile(input, inputRead);
//        char a = input[index];
        if(input[index] == '|'){
            inputRead++;
            index++;
            S2(input);
        }
        else if (EndofFile(input, inputRead)){
            //If it's the end of file I return a comment with nothing else
            SF(input);
        }
        //If it's just a line comment I go until the end of line, I branched off to a different line
        else if (input[index]){
            S2b(input);
        }

    }

    //This is the line comment branch
    void S2b (const std::string& input){
//        bool b = EndofFile(input, inputRead);
//        char a = input[index];

        if (input[index]){
            if(input[index] != '\n'){
                inputRead++;
                index++;
                S2b(input);
            }
            //if it is a newline then the line comment is done
            else SF(input);
        }
        //If there isnt input at index then the line comment is over
        // It shouldn't get here.
        else SF(input);
    }

    void S2 (const std::string& input){
//        char a = input[index];
//        bool b = EndofFile(input, inputRead);

        if(input[index]== '|'){
            inputRead++;
            index++;
            S3(input);
        }
        else if (EndofFile(input, inputRead+1)){
            CommentSerr();
        }else if (input[index]) {
            //This is where I will check for new lines
            if (input[index] == '\n'){
                newLines++;
            }
            inputRead++;
            index++;
            S2(input);
        }

        else Serr();

    }

    void S3 (const std::string& input) {
//        char a = input[index];
//        bool b = EndofFile(input, inputRead);

        if(input[index] == '#'){
            inputRead++;
            SF(input);
            //Time to go to a accept state.
        }
        else if(EndofFile(input,inputRead+1)){
            CommentSerr();
        }
        else if(input[index]){
            //This is where I will check for new lines
            if (input[index] == '\n'){
                newLines++;
            }
            //Whatever I have it goes into the comment
            inputRead++;
            index++;
            S2(input);
        }
        else{
            Serr();
        }

    }

    void SF(const std::string& input){
//        char a = input[index];
//        bool b = EndofFile(input, inputRead);

        //This is the accept state and is really just here for my visual pleasure.
    }
public:
    FSA_Comment() : Automaton(TokenType:: COMMENT) {}


    void S0  (const std::string& input){
        //char a = input[index];
        if(input[index] == '#'){
            index++;
            inputRead++;
            S1(input);
        }
    }


};




#endif //CS236_PROJECT1_FSA_COMMENT_H
