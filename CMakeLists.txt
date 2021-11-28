cmake_minimum_required(VERSION 3.20)
project(CS236_Project1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CS236_Project1
        Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        Lexer.cpp
        Lexer.h
        main.cpp
        Token.cpp
        Token.h FSA_Queries.h Undefined.h FSA_L_Paren.h FSA_R_Paren.h FSA_Comma.h FSA_Multiply.h FSA_String.h FSA_Rules.h FSA_Schemes.h FSA_Facts.h FSA_ID.h FSA_Comment.h)

