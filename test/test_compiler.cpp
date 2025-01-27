#include <catch2/catch_test_macros.hpp>
#include "compiler/Lexer.hpp"

TEST_CASE("Lexer tokenizes numbers and operators", "[lexer]") {
  Lexer lexer("123 + 456");
  Token token = lexer.nextToken();
  REQUIRE(token.type == TokenType::Number);
  REQUIRE(token.value == "123");
  
  token = lexer.nextToken();
  REQUIRE(token.type == TokenType::Plus);
}