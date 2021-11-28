#ifndef CS236_PROJECT1_FSA_QUERIES_H
#define CS236_PROJECT1_FSA_QUERIES_H

#include "Automaton.h"
#include <string>

class FSA_Queries : public Automaton
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
        if (input[index] == 'e'){
            inputRead++;
            index++;
            S3(input);
        }
        else{ Serr();}
    }
    void S3(const std::string& input){
        if (input[index] == 'r'){
            inputRead++;
            index++;
            S4(input);
        }
        else{ Serr();}

    }
    void S4(const std::string& input){
        if (input[index] == 'i'){
            inputRead++;
            index++;
            S5(input);
        }
        else{ Serr();}

    }
    void S5(const std::string& input){
        if (input[index] == 'e'){
            inputRead++;
            index++;
            S6(input);
        }
        else{ Serr();}

    }
    void S6(const std::string& input){
        if (input[index] == 's'){
            inputRead++;
            //accept state!
        }
        else{ Serr();}

    }


public:
    FSA_Queries() : Automaton(TokenType:: QUERIES) {}


  void S0(const std::string& input){
        if (input[index] == 'Q'){
            inputRead++;
            index++;
            S1(input);
        }
        else{
            Serr();
        }
    }



};

#endif //CS236_PROJECT1_FSA_QUERIES_H
