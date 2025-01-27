#include "compiler/Parser.hpp"

Parser::Parser(Lexer &lexer) : lexer(lexer) {
  advance();
}

void Parser::advance() {
  currentToken = lexer.nextToken();
}

std::unique_ptr<ASTNode> Parser::parse() {
  return parseExpression();
}

std::unique_ptr<ASTNode> Parser::parseExpression() {
  auto node = parseTerm();
  while (currentToken.type == TokenType::Plus || currentToken.type == TokenType::Minus) {
    Token op = currentToken;
    advance();
    node = std::make_unique<BinaryOpNode>(op.type, std::move(node), parseTerm());
  }
  return node;
}

// Implement parseTerm(), parseFactor(), parsePrimary() similarly...