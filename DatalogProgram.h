
#ifndef CS236_PROJECT1_DATALOGPROGRAM_H
#define CS236_PROJECT1_DATALOGPROGRAM_H

#include "Predicate.h"
#include "Rule.h"
#include <set>
#include <string>

class DatalogProgram
{

private:
    std::vector<Predicate*> schemes;
    std::vector<Predicate*> facts;
    std::vector<Predicate*> queries;
    std::vector<Rule*> rules;
    std::set<std::string > domain;


public:
    DatalogProgram(){}
    DatalogProgram(std::vector<Predicate*> schemes,
                  std::vector<Predicate*> facts,
                  std::vector<Predicate*> queries,
                  std::vector<Rule*> rules,
                  std::set<std::string> domain){

        this->schemes = schemes;
        this->facts = facts;
        this->queries = queries;
        this->rules = rules;
        this->domain = domain;
    }
    ~DatalogProgram(){}


public:

    std::string toString(){
        std::stringstream outy;
        outy<< "Schemes("<<schemes.size() << "):\n";
        outy<< schemesString();
        outy<< "Facts(" << facts.size() << "):\n";
        outy<< factsString();
        outy << "Rules("<< rules.size() << "):\n";
        outy << rulesString();
        outy << "Queries("<< queries.size()<<"):\n";
        outy<< queriesString();
        outy<< "Domain(" << domain.size() <<"):\n";
        outy<< domainString();


        return outy.str();
    }

    std::string schemesString(){
        //I wrote this tostring before I wrote a general predicate tostring
        std::stringstream out;
        for(unsigned int i = 0; i < schemes.size(); i++){
            out<<"  "<<schemes[i]->getID()<<"(";
            for (int j =0; j < schemes[i]->getNumParam(); j++){
                out<<schemes[i]->getParamAtI(j);
                if (j<schemes[i]->getNumParam()-1){
                    out <<",";
                }
            }
            out<< ")\n";
        }
        return out.str();
    }
    std::string  factsString(){
        std::stringstream out;
        for(unsigned int i = 0; i< facts.size();i++){
            out<<"  "<<facts[i]->toString()<<".\n";
        }
        return out.str();
    }
    std::string rulesString(){
        std::stringstream out;
        for(unsigned int i = 0; i< rules.size();i++){
            out<<"  "<<rules[i]->toString() <<".\n";
        }
        return out.str();
    }
    std::string queriesString(){
        std::stringstream out;
        for(unsigned int i = 0; i< queries.size();i++){
            out<<"  "<< queries[i]->toString()<<"?\n";
        }
        return out.str();
    }
    std::string domainString(){
        std::stringstream out;
        for( auto it = domain.begin();it != domain.end();++it){
            out<< "  "<<*it <<"\n";
        }
        return out.str();
    }



    //Lab3 stuff
    unsigned int numSchemes(){
        return schemes.size();
    }
    std::string schemeIDAtI(int i){
        return schemes[i]->getID();
    }
    unsigned int schemeSizeAtI(int i){
        return schemes[i]->getNumParam();
    }
    std::string getSchemeParamAtIJ(int i , int j){

        return schemes[i]->getParamAtI(j);
    }


    unsigned int numFacts(){
        return facts.size();
    }
    std::string factIDAtI(int i){
        return facts[i]->getID();
    }
    unsigned int factSizeAtI(int i){
        return facts[i]->getNumParam();
    }
    std::string getFactParamAtIJ(int i , int j){

        return facts[i]->getParamAtI(j);
    }

    unsigned int numQueries(){
        return queries.size();
    }

    Predicate queryAtI(int i){
        // I don't know how this works but it sends the right predicate
        return *queries[i];
    }

    ////Lab 4 Stuff
    unsigned int numRules(){
        return rules.size();
    }
    Rule ruleAtI(int i){
        return *rules[i];
    }
};


#endif //CS236_PROJECT1_DATALOGPROGRAM_H
