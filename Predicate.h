//
// Created by Joseph Wilson on 10/2/2021.
//

#ifndef CS236_PROJECT1_PREDICATE_H
#define CS236_PROJECT1_PREDICATE_H



#include "Parameter.h"
#include <vector>
#include <sstream>


class Predicate {
private:
    std::string id;
    std::vector<Parameter*> myPredicate;
public:
    Predicate(){
        this->id = "";
        //this->myPredicate = nullptr;
    }
    //I'm going to overload the Predicate constructor to make a predicate when parsing.
    Predicate(std::vector<std::string> IDs){
        this->id = IDs[0];
        for(unsigned int i = 1; i < IDs.size(); i++){
            Parameter* param = new Parameter(IDs[i]);
            myPredicate.push_back(param);
        }
    }

    std::string toString(){
        std::stringstream out;
        out <<id <<"(";
        for (unsigned int i = 0; i<myPredicate.size();i++){
            out<< myPredicate[i]->getParam();
            if(i<myPredicate.size()-1){
                out<<",";
            }

        }
        out<<")";
        return out.str();
    }


//    void setID(std::string idy){
//        this->id = idy;
//    }

    std::string getID(){
        return id;
    }
    int getNumParam(){
        return myPredicate.size();
    }

    std::string getParamAtI(int index){
        return myPredicate[index]->getParam();
    }

    bool isParamAtIConst(int i){
        return myPredicate[i]->isConstant();
    }


    //Lab4 stuff
    std::vector<std::string> predicateValues(){
        std::vector<std::string> output;
        for(unsigned int i = 0; i < myPredicate.size(); i++){
            output.push_back(myPredicate[i]->getParam());
        }
        return output;
    }


};


#endif //CS236_PROJECT1_PREDICATE_H
