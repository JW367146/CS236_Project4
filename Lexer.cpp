#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "FSA_L_Paren.h"
#include "FSA_R_Paren.h"
#include "FSA_Comma.h"
#include "FSA_Period.h"
#include "FSA_Q_Mark.h"
#include "FSA_Add.h"
#include "FSA_Multiply.h"

#include "FSA_Rules.h"
#include "FSA_Facts.h"
#include "FSA_Schemes.h"
#include "FSA_Queries.h"

#include "FSA_String.h"
#include "FSA_ID.h"
#include "FSA_Comment.h"

#include "Undefined.h"

#include <cctype>

using namespace std;


Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    //These are my simple one-ish character FSAs
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new FSA_L_Paren());
    automata.push_back(new FSA_R_Paren());
    automata.push_back(new FSA_Comma());
    automata.push_back(new FSA_Multiply());
    automata.push_back(new FSA_Add());
    automata.push_back(new FSA_Period());
    automata.push_back(new FSA_Q_Mark());
    //These are my KeyWord FSAs
    automata.push_back(new FSA_Queries());
    automata.push_back(new FSA_Rules());
    automata.push_back(new FSA_Facts());
    automata.push_back(new FSA_Schemes());

    //These are my FSA that require more thinking
    automata.push_back(new FSA_ID());
    automata.push_back(new FSA_String());
    automata.push_back(new FSA_Comment());

}

void Lexer::Run(std::string& input) {


    //We set this to 1
    lineNumber = 1;


    //// This is where we read everthing
    while (input.size() > 0)
    {

        maxRead = 0;
        maxAutomaton = automata[1];


        //Before we  start reading input let's skip over white space
        char firstChar = input[0];

        //And if we are at the end of file the input will just be \n and we'll make an end of file token
        //The input size will be just 1
        int inputSizy = input.size();
        if(firstChar == '\n' && inputSizy == 1){
            //This means I'm at the end of file

            tokens.push_back(new Token(TokenType::eof, "", lineNumber));
        }

        //If it's not white space then read everything in and continue
        if(!isspace(firstChar)){

            /// Run all the FSA on the input
            for(long unsigned int i = 0; i < automata.size(); i++){

                long unsigned int inputRead = automata[i]->Start(input);
                if (inputRead > maxRead){
                    maxRead = inputRead;
                    maxAutomaton = automata[i];
                }
            }

            // No2 we put the best match in our tokens
            if (maxRead > 0){
                string tokenInput;
                for (long unsigned int i =0; i < maxRead;i++){
                    tokenInput += input[i];
                }
                newToken = maxAutomaton->CreateToken(tokenInput, lineNumber);
                for (long unsigned int i = 0; i<maxAutomaton->NewLinesRead(); i++){
                    lineNumber++;
                }
                tokens.push_back(newToken);


            }
            else {
                //If we didn't succeed in any FSA then we have undefined character
                maxRead = 1;
                //Let's make an undefined auto
                Automaton* undefined = new Undefined();
                //We want to pass in the first char in the input string
                string tokenInput;
                tokenInput += input[0];
                newToken = undefined->CreateToken( tokenInput, lineNumber );
                tokens.push_back(newToken);
            }

        }
        else if(firstChar == '\n'){
            //I'm going to control for newlines here
            lineNumber++;
            maxRead = 1;
        }
        else {
            // If it is space, we still need to increase the read that we use below to get newInput
            maxRead = 1;
        }




        //Now we have made our tokens we need to cut off that bit from the input
        string nextInput;
        //We are going to make a string of size input - maxRead
        int inputSize = input.size();
        for(unsigned int i = 0; i < inputSize-maxRead; i++){
            nextInput +=input[i+maxRead];
        }
        //And then we replace input with the nextInput
        input = nextInput;
    }

}
