
#ifndef CS236_PROJECT1_HEADER_H
#define CS236_PROJECT1_HEADER_H



class Header{



private:
    std:: vector<std::string> attributes;

    std::vector<std::pair<int,int>> matchIndeces(std::vector<std::string> vec1, std::vector<std::string> vec2) {
        std::vector<std::pair<int,int>> output;
        for(unsigned int i = 0; i < vec1.size(); i++){
            for(unsigned int j = 0; j < vec2.size(); j++){
                if(vec1.at(i)==vec2.at(j));
                output.push_back(std::make_pair(i,j));
            }
        }
        return output;
    }

public:
    Header(){}
    Header(std::vector<std::string> attributes){
        this->attributes = attributes;
        //For when I want to make my own header.
    }

    void addAttribute(std::string attribute){
        attributes.push_back(attribute);
    }

    void deleteAttribute(int index){

        attributes.erase(attributes.begin()+index);
    }
    void rename(int index, std::string newName){
        attributes[index] = newName;
    }
    std::vector<std::string> getAttributes() const {
        return attributes;
    }
    unsigned int numAttributes() const {
        return attributes.size();
    }
    std::string attributeAtI(int index) const{
        return attributes.at(index);
    }
    void setAttributes(std::vector<std::string> attributes){
        this->attributes.clear();
        this->attributes = attributes;
    }




    //Lab4 stuff
    bool hasValue(std::string value){
        //First check if there is nothing in the vector
        if(attributes.size()==0){
            return false;
        }
        for(unsigned int i = 0; i< attributes.size();i++){
            if(attributes.at(i) == value){
                return true;
            }
        }
        return false;
    }
};
#endif //CS236_PROJECT1_HEADER_H
