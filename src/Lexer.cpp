#include "compiler/Lexer.hpp"
#include <cctype>
#include <stdexcept>

Lexer::Lexer(const std::string &input) : input(input) {}

Token Lexer::nextToken(){
    skipWhitespace();
    if(currentPos >= input.size()) return {TokenType::End, "", currentPos};

    char currentChar = input[currentPos];
    size_t startPos = currentPos;


    //Handle numbers (Only integers in this project)
    if (isdigit(currentChar)){
        std::string num;
        while(currentPos < input.size() && isdigit(input[currentPos])) {
            num += input[currentPos++];
        }
        return {TokenType::Number, num, startPos};
    }

    //Handle Operators
    switch(currentChar){
        case '+': currentPos++; return {TokenType::Plus,"+",startPos};
        case '-': currentPos++; return {TokenType::Minus, "-", startPos};
        case '*': currentPos++; return {TokenType::Multiply, "*", startPos};
        case '/': currentPos++; return {TokenType::Divide, "/", startPos};
        case '(': currentPos++; return {TokenType::LParen, "(", startPos};
        case ')': currentPos++; return {TokenType::RParen, ")", startPos};
        default: throw std::runtime_error("Unexpected character at position " + std::to_string(currentPos));

    }
}

void Lexer::skipWhitespace(){
    while (currentPos < input.size() && isspace(input[currentPos])) {
        currentPos++;
    }
}


