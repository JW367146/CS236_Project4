

#ifndef CS236_PROJECT1_KEYVALUES_H
#define CS236_PROJECT1_KEYVALUES_H


class KeyValues
{
private:
std::string key;
std::vector<int> values;

public:
    KeyValues(std::string key){
        this->key = key;
    }

    void addValue(int value){
        values.push_back(value);
    }

    std::string toString() const
    {
        std::stringstream out;

        return out.str();
    }

    friend std::ostream& operator<< (std::ostream& os,  KeyValues& myclass)
    {
        os << myclass.toString();
        return os;
    }

};


#endif //CS236_PROJECT1_KEYVALUES_H
