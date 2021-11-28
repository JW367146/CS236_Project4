

#ifndef CS236_PROJECT1_DATABASE_H
#define CS236_PROJECT1_DATABASE_H


#include "Relation.h"
#include <map>

class Database{

private:
    std::map<std::string, Relation> mappy;
protected:


public:
    Database(){}
    ~Database(){}

    unsigned int getTotalSize(){
        unsigned int output= 0;
        for(auto it = mappy.begin(); it != mappy.end(); ++it){
            output += it->second.numTuples();
        }
        return output;
    }

    void addRelation(std::string name, Relation relation){
        mappy.insert(std::pair <std::string, Relation> (name,relation));
    }

    void addTuple(std::string relation, Tuple tuple){
        mappy[relation].insertTuple(tuple);
    }

    bool tryAddTuple(std::string relation, Tuple tuple){
        //mappy[relation].tryInsertTuple(tuple);
        return mappy[relation].tryInsertTuple(tuple);

    }

    Relation getRelation(std::string name){
        return mappy[name];
    }

};



#endif //CS236_PROJECT1_DATABASE_H
