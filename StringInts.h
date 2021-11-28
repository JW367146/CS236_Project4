
#ifndef CS236_PROJECT1_STRINGINTS_H
#define CS236_PROJECT1_STRINGINTS_H

class StringIntVector
{

private:
    std::string name;
    std::vector<int> ints;

public:
    StringIntVector(std::string name){
        this->name = name;
    }
    ~StringIntVector();

    void addInt(int integer){
        ints.push_back(integer);
    }

};


#endif //CS236_PROJECT1_STRINGINTS_H
