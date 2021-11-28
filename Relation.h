
#ifndef CS236_PROJECT1_RELATION_H
#define CS236_PROJECT1_RELATION_H


#include "Tuple.h"
#include "Header.h"

using namespace std;
#include<string>


class Relation{

private:

    Header header;
    std::string name;
    std::set<Tuple> tuples;
    //I'm going to make a vector of tuples copied from the set because it's easier;
    std::vector<Tuple>  vectorTuples;




    std::vector<std::pair<int,int>> matchIndeces(std::vector<std::string> vec1, std::vector<std::string> vec2) {
        std::vector<std::pair<int,int>> output;
        for(unsigned int i = 0; i < vec1.size(); i++){
            for(unsigned int j = 0; j < vec2.size(); j++){
                if(vec1.at(i)==vec2.at(j)) {
                    output.push_back(std::make_pair(i, j));
                }
            }
        }
        return output;
    }

    std::pair<int,int> repeatedAttributes(Relation* relation){
        std::vector<std::string> attributes = relation->getAttributes();
        for(unsigned int i = 0; i < attributes.size(); i++){
            for(unsigned int j = 0; j< attributes.size();j++){
                if(attributes.at(i) == attributes.at(j) && i != j){
                    return std::make_pair(i,j);
                }
            }
        }
        //Now that we have gone through the whole thing, we return true
        return std::make_pair(-1,-1);
    }


public:
    Relation(){}
    Relation(std::string name){
        this->name = name;
    }
    Relation(std::string name, Header header){
        this->header = header;
        this->name = name;
    }
    Relation(std::string name, Header header, std::set<Tuple> tuples){
        //For when I want to make a full relation off the bat.
        this->header = header;
        this->name = name;
        this->tuples = tuples;
    }
    Relation(Header header){
        this->header = header;
    }

    void insertTuple(Tuple tuple){
        tuples.insert(tuple);
    }
    bool tryInsertTuple(Tuple tuple){
        //auto what = tuples.insert(tuple).second;

        return tuples.insert(tuple).second;
    }
    std::vector<std::string> getAttributes(){
        return header.getAttributes();
    }
    void setName(std::string name){
        this->name = name;
    }
    void setVectorTuples() {
        for(auto it = tuples.begin(); it != tuples.end(); ++it){
            vectorTuples.push_back(*it);
        }
    }
    void setHeader(Header header)  {
        this->header = header;
    }
    std::set<Tuple>::iterator tuplesBegin(){
        return tuples.begin();
    }
    std::set<Tuple>::iterator tuplesEnd(){
        return tuples.end();
    }
    std::string getName(){
        return name;
    }


    Relation select(Relation* input, int attributeIndex, std::string constant ){

        //I'm going to copy the relation I just passed in
        Relation output = Relation(input->name, input->header);


        //Need to iterate over the set of tuples and remove the ones that don't have the value.
        std::set<Tuple>::iterator it;
        //First let's just find which ones will be removed and remove them after.
        std::vector<std::set<Tuple>::iterator> iterators;
        for(it = input->tuples.begin();it != input->tuples.end(); ++it){
            Tuple currentTuple = *it;
           if(currentTuple.valueAtI(attributeIndex) != constant){
               iterators.push_back(it);
           }
        }
        //Now we need to remove from the set of tuples all the tuples we found.
        for(unsigned int i = 0; i < iterators.size();i++){
            input->tuples.erase(iterators.at(i));
        }
        output.tuples = input->tuples;
        return output;
    }

    Relation project(Relation* input, int attributeIndex){
        Relation output = Relation(input->name,input->header);
        output.header.deleteAttribute(attributeIndex);
        //I need to make a new set of tuples that I will fill after I remove the attribute at index.
        std::set<Tuple> newTuples;
        std::set<Tuple>::iterator it;
        for ( it = input->tuples.begin(); it != input->tuples.end(); ++it){
            Tuple tempTuple = *it;
            std::vector<std::string> newTuple = tempTuple.getValues();
            newTuple.erase(newTuple.begin()+attributeIndex);
            newTuples.insert(newTuple);
        }
        //I need to add these tuples to the output tuple.
        output.tuples = newTuples;

        return output;
    }

    Relation rename(Relation* input, int attributeIndex, std::string attribute){
        //This takes in the new name for the attribute;
        Relation output = Relation(input->name, input->header,input->tuples);
        output.header.rename(attributeIndex,attribute);
        return output;

    }

    Relation selectTwo(Relation* input, int attributeIndex1, int attributeIndex2 ){
        Relation output = Relation(input->name,input->header);//I'm just keeping the name

        std::set<Tuple>::iterator it;
        std::vector<std::set<Tuple>::iterator> iterators;
        std::set<Tuple> newTuples;

        for( it = input->tuples.begin(); it != input->tuples.end(); ++it){
            Tuple currentTuple = *it;
            if (currentTuple.valueAtI(attributeIndex1) != currentTuple.valueAtI(attributeIndex2)){
                //If there are not equivelant then we want to delete them. So we add them to the list of things to delete.
                iterators.push_back(it);
            }
            else if (currentTuple.valueAtI(attributeIndex1) == currentTuple.valueAtI(attributeIndex2)){
                //Do nothing.
            }
        }
        //Now we need to delete all the tuples where there is no match at the right attribute.
        for(unsigned int i = 0; i < iterators.size();i++){
            input->tuples.erase(iterators.at(i));
        }
        output.tuples = input->tuples;
        return output;
    }

    std::string result(){
        std::stringstream out;
        unsigned int numRows = tuples.size();
        if(!numRows){
            out<< "No\n";
        }
        else{
            out << "Yes(" <<numRows << ")\n";
        }

        return out.str();
    }

    std::string toString() const
    {

        //First check if there are any attributes left.
        if(!header.numAttributes()){
            return "";
        }
        std::stringstream out;

        //The tuples are the rows, the attributes are the columns.
        for(auto  it = tuples.begin(); it != tuples.end(); ++it){
            out <<"  ";
            for (unsigned int j = 0; j < header.numAttributes(); j++){
                out<< header.attributeAtI(j) <<"= "<< it->valueAtI(j);
                if(j < header.numAttributes()-1){
                    out <<", ";
                }

            }
            out<<"\n";

        }


        return out.str();
    }

    friend std::ostream& operator<< (std::ostream& os,  Relation& myclass)
    {
        os << myclass.toString();
        return os;
    }



    ////Lab 4 stuff

    Relation join(const Relation* beta){ Relation output;
        //This function combines alpha (the member this) and Beta (the second relation to join)
        Relation* alpha = this;// I want to look at alpha instead of this for aesthetic reasons.


        //Combine headers. We add all of alphas, then we add the unique members of beta.
        Header newHeader;
        //I changed my mind. We are going to add all the attributes, then project them down to the unique ones at the end.
        for(unsigned int i = 0; i < alpha->header.numAttributes();i++){
//            if(!newHeader.hasValue(alpha->header.attributeAtI(i))) {
//                newHeader.addAttribute(alpha->header.attributeAtI(i));
//            }
            newHeader.addAttribute(alpha->header.attributeAtI(i));
        }
        for(unsigned int i = 0; i< beta->header.numAttributes();i++){
//            if(!newHeader.hasValue(beta->header.attributeAtI(i))){
//                newHeader.addAttribute(beta->header.attributeAtI(i));
//            }
            newHeader.addAttribute(beta->header.attributeAtI(i));
        }
        output.setHeader(newHeader);

        //Find pairs of matching attributes in the two headers.
        //This will hold all pairs of indeces with matching attributes
        auto matches = matchIndeces(alpha->header.getAttributes(), beta->header.getAttributes());


        //Now we find which tuples of the relations are compatible.

       // Relation newBeta = project(const_cast<Relation *>(beta), matches[0].second);

        //I need to loop alpha,
        // loop beta,
        // and then loop through the matches to see if they are all the same.
        for(unsigned int i = 0; i<alpha->vectorTuples.size();i++){
            for(unsigned int j = 0; j<beta->vectorTuples.size();j++){
                //We'll start with it being true, and anything that doesn't match will change it to false.
                bool compatibleTuples = true;
                for(unsigned int k =0; k < matches.size();k++){
                    //These two are the attributes that must match if
                    std::string a = alpha->vectorTuples[i].valueAtI(matches[k].first);
                    std::string b = beta->vectorTuples[j].valueAtI(matches[k].second);
                    if( a != b){
                        compatibleTuples = false;
                    }
                }

                //Now if the i j pair of tuples are compatible we want to add them to the new relationship.
                if(compatibleTuples){
                   std::vector<std::string> alphaVector = alpha->vectorTuples[i].getValues();
                   std::vector<std::string> betaVector = beta->vectorTuples[j].getValues();
                   alphaVector.insert(alphaVector.end(), betaVector.begin(), betaVector.end());
                   Tuple joinedTuple(alphaVector);//The alpha vector is joined with the beta vector;
                    output.insertTuple(joinedTuple);

                }
            }
        }

        //Ok so now I need to project away the columns from beta that are repeats.
        //This is a similar block of code pulled from evalQuery in Interpreter.h
        while (repeatedAttributes(&output).first != -1){
            //Attributes at indeces i and j are the same so we need to do a type two select on them.
            auto ij = repeatedAttributes(&output);
            output = output.selectTwo(&output, ij.first,ij.second);////selecttwo is redundant in join.

            //After we delete the rows that don't have matching values at the attributes, we need to delete the second, matching attribute column.
            output = output.project(&output,ij.second);
        }

        output.setName(alpha->name + beta->name);//This is just bc I want to
        return output;
    }

    Relation projectHead(Relation* input, std::vector<std::string> newHeader){
        //This function will work primarily with the vectorTuples.

        auto matches = matchIndeces(newHeader, input->header.getAttributes());
        Header outputHeader(newHeader); //The attributes are going to be the same.

        Relation output = Relation(outputHeader);

        for(unsigned int i = 0; i< vectorTuples.size();i++){
            Tuple newTuple;
            for(unsigned int j = 0; j< matches.size();j++){
               newTuple.addParam(vectorTuples[i].valueAtI(matches[j].second));
            }
            output.insertTuple(newTuple);
        }

        return output;
    }

    Relation renameHead(Relation* input, Relation* head){
        //I bet it's suffidience to construct a new Relation that has the name and header of the head rule and the tuples of the joined stuff.
       //Relation output = Relation(head->name,head->header,input->tuples);
        return Relation(head->name,head->header,input->tuples);
        //        for(unsigned int i =0; i< head->header.numAttributes();i++){
//
//        }
    }

    unsigned int numTuples(){
        return tuples.size();
    }



};



#endif //CS236_PROJECT1_RELATION_H
