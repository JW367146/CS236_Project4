#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <sstream>

enum class TokenType {
    COLON,
    COLON_DASH,
    LEFT_PAREN,
    RIGHT_PAREN,
    COMMA,
    MULTIPLY,
    PERIOD,
    ADD,
    Q_MARK,

    QUERIES,
    RULES,
    FACTS,
    SCHEMES,

    STRING,
    ID,
    COMMENT,
    UNDEFINED,
    eof
};

class Token
{
private:

    // TODO: add member variables for information needed by Token
    // I'm adding in all of the member variables.
    TokenType type;
    std::string description;
    int line;


public:
    Token(TokenType type, std::string description, int line);

    // TODO: add other needed methods

    std::string toString() {
        std::stringstream outy;
        outy << "(" << tokenTypeStr(type) << ",\"" << description << "\"," << line <<")\n";
        return outy.str();
    }

    friend std::ostream& operator<< (std::ostream& os,  Token& myclass)
    {
        os << myclass.toString();
        return os;
    }


    std::string getDescription(){
        return description;
    }




    std::string tokenTypeStr(TokenType input){
        if(input == TokenType::COLON){
            return "COLON";
        }
        else if (input == TokenType::COLON_DASH){
            return "COLON_DASH";
        }
        else if (input == TokenType::COMMA){
            return "COMMA";
        }
        else if (input == TokenType::LEFT_PAREN){
            return "LEFT_PAREN";
        }
        else if(input == TokenType::RIGHT_PAREN){
            return "RIGHT_PAREN";
        }
        else if(input == TokenType::MULTIPLY){
            return "MULTIPLY";
        }
        else if(input == TokenType::ADD){
            return "ADD";
        }
        else if(input == TokenType::Q_MARK){
            return "Q_MARK";
        }
        else if (input ==TokenType::PERIOD){
            return "PERIOD";
        }
        else if (input == TokenType::SCHEMES){
            return "SCHEMES";
        }
        else if (input == TokenType::FACTS){
            return "FACTS";
        }
        else if (input ==TokenType::RULES){
            return "RULES";
        }
        else if (input== TokenType::QUERIES){
            return "QUERIES";
        }
        else if (input == TokenType::ID){
            return "ID";
        }
        else if (input == TokenType::STRING){
            return "STRING";
        }
        else if (input == TokenType::COMMENT){
            return "COMMENT";
        }
        else if (input == TokenType::UNDEFINED){
            return "UNDEFINED";
        }
        else if (input == TokenType::eof){
            return "EOF";
        }
        else return "whoops";
    }


    //Lab2 additions
    TokenType getType(){
        return type;
    }
};

#endif // TOKEN_H

