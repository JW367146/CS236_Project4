#ifndef CS236_PROJECT1_TUPLE_H
#define CS236_PROJECT1_TUPLE_H



class Tuple{

private:
    std::vector<std::string> values;



public:
    Tuple(){}
    //Overload the constructor for when I want to make new tuples
    Tuple(std::vector<std::string> newTuple){
        this->values = newTuple;
    }
    ~Tuple(){}
    void addParam(std::string param){
        values.push_back(param);
    }

    bool operator< (const Tuple &rhs) const {
        return values < rhs.values;
    }

    std::string valueAtI(int i ) const {
        return values.at(i);
    }

    void deleteAttribute(int index) {
        values.erase(values.begin()+index);
    }

    std::vector<std::string> getValues() const {
        return values;
    }


};


#endif //CS236_PROJECT1_TUPLE_H
