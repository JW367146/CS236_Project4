//
// Created by Joseph Wilson on 10/2/2021.
//

#ifndef CS236_PROJECT1_PARAMETER_H
#define CS236_PROJECT1_PARAMETER_H

#include <string>

class Parameter {
private:
    std::string param;
    bool constant;
public:
    Parameter(){}
    Parameter(std::string param){
        this->param = param;

        //Check to see if it's a string.
        char a = param[0];
        if (a == '\''){
            constant = true;
        }else constant = false;
    }
    ~Parameter(){}
    std::string getParam(){
        return param;
    }

    bool isConstant(){
        return constant;
    }



};


#endif //CS236_PROJECT1_PARAMETER_H
