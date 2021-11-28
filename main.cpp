#include "Lexer.h"
#include "iostream"
#include "fstream"
#include "Token.h"
#include "Parser.h"
#include "Interpreter.h"

using namespace std;

int main(int argc, char** argv) {


    //// Main Part 1
    // I need to make sure I have command line argus.
    string fileName;
    // I need to make sure I have a command line to run.
    if (argv[1]){
        fileName = argv[1];
    }
    else {
        cout << "Missing commandline argument\n\n";
        return 1;
    }








    //Well now I want my whole input file as a string that I will send to run on the lexer.
    ifstream myFile;
    myFile.open(fileName);
    string lines;
    while (!myFile.eof()){
        string newLine;
        getline(myFile, newLine);
        lines = lines + newLine + '\n';
    }
    //Now lines has all the whole input file as one string.












//I'm making a lexer here and I will pass the input to it with Run.
    Lexer* lexer = new Lexer();
    lexer->Run(lines);

    //// I only need to out the tokens for Lab1
    //cout << lexer->toString();



    //// START OF LAB2 STUFF
    //Let's just take out the tokens from the lexer
    vector<Token*>  lexerTokens = lexer->getTokens();
    vector<Token*> tokens;
    //Let's delete the comments tokens
    //vector<Token*> tokensCopy = tokens;

    for (unsigned int i = 0; i < lexerTokens.size();i++){
        if(lexerTokens[i]->getType() != TokenType:: COMMENT ){
            tokens.push_back(lexerTokens[i]);
        }
    }

    //Let's make a Parser why not?
    Parser* parser = new Parser(tokens);

    //now we need to parse the tokens
    bool parsed = parser->parse();


    //Lab2 Output
    if(parsed){
//        cout<< "Success!\n";
//        cout<< parser->datalogProgram.toString();
    }
    if(!parsed){
//        cout << "Failure!\n  ";
//        cout<< parser->getException();
    }




    //Start of lab 3 stuff

    Interpreter interpreter = Interpreter(parser->datalogProgram);
    interpreter.evalRules();//Lab 4 stuff
   // interpreter.evalQueries();

    cout << interpreter.toString();




    delete lexer;
    return 0;
}