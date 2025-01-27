#pragma once

#include <string>
#include <vector>

enum class TokenType{
    Number,
    Plus,
    Minus,
    Multiply,
    Divide,
    LParen,
    RParen,
    End
};

struct Token{
    TokenType type;
    std::string value; //For numbers 1,2,3,4
    size_t pos;  //position in input
};

class Lexer{
public:
    explicit Lexer(const std::string &input);
    Token nextToken();

private:
    std::string input;
    size_t currentPos = 0;
    void skipWhitespace();
};