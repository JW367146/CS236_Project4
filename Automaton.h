#ifndef AUTOMATON_H
#define AUTOMATON_H
#include "Token.h"

class Automaton
{
protected:
    int inputRead = 0;
    int newLines = 0;
    int index = 0;
    TokenType type;


//    //I want to know if I'm at the end of the file
//    bool EOF (const std::string inputy, const int inputReady){
//        inputSize = input.size();
//        if (inputReady == inputSize){
//            return true;
//        }
//        else return false;
//    }

public:
    // Default constructor -- since we have a constructor that takes a parameter,
    //   the compiler will autogenerate a default constructor if not explicit.
    Automaton() : Automaton(TokenType::UNDEFINED) {}

    Automaton(TokenType type) { this->type = type; }

    // Start the automaton and return the number of characters read
    //   read == 0 indicates the input was rejected
    //   read  > 0 indicates the input was accepted

    int Start(const std::string& input) {
        newLines = 0;
        inputRead = 0;
        index = 0;
        S0(input);
        return inputRead;
    }

    ////I want this to tell me if the file is at the end
    bool EndofFile (std::string inputy, int inputReady){
        int inputSizey = inputy.size();
        if (inputReady == inputSizey){
            return true;
        }
        else return false;
    }

    // Every subclass must define this method
    virtual void S0(const std::string& input) = 0;




    void Serr() {
        // Indicate the input was rejected
        inputRead = 0;
    }
    void StringSerr() {
        //I need a seperate error for strings when they get to the end of file becuase I need to not make inputRead = 0;
        //I just need to change the type to undefined
        type = TokenType::UNDEFINED;
        // I'm rolling back the inputRead by one so it will see the end of file.
        //inputRead--;
    }

    void CommentSerr(){
    //We also need a seperate error for comments for the same reason.
    type = TokenType::UNDEFINED;
    //Now we roll back.
    //inputRead--;
    }

    virtual Token* CreateToken(std::string input, int lineNumber) { return new Token(type, input, lineNumber); }

    long unsigned int NewLinesRead() const { return newLines; }
};

#endif // AUTOMATON_H

