#pragma once
#include "Lexer.hpp"
#include <memory>

struct ASTNode {
  virtual ~ASTNode() = default;
};

struct NumberNode : ASTNode {
  int value;
  explicit NumberNode(int value) : value(value) {}
};

struct BinaryOpNode : ASTNode {
  TokenType op;
  std::unique_ptr<ASTNode> left;
  std::unique_ptr<ASTNode> right;
  BinaryOpNode(TokenType op, std::unique_ptr<ASTNode> left, std::unique_ptr<ASTNode> right)
    : op(op), left(std::move(left)), right(std::move(right)) {}
};

class Parser {
public:
  explicit Parser(Lexer &lexer);
  std::unique_ptr<ASTNode> parse();

private:
  Lexer &lexer;
  Token currentToken;
  void advance();
  std::unique_ptr<ASTNode> parsePrimary();
  std::unique_ptr<ASTNode> parseExpression();
  std::unique_ptr<ASTNode> parseTerm();
  std::unique_ptr<ASTNode> parseFactor();
};

