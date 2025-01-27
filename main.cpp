#include "compiler/Lexer.hpp"
#include "compiler/Parser.hpp"
#include "compiler/CodeGen.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: tinycc <input-file>\n";
    return 1;
  }

  std::ifstream input(argv[1]);
  std::string source((std::istreambuf_iterator<char>(input)), 
                     std::istreambuf_iterator<char>());

  Lexer lexer(source);
  Parser parser(lexer);
  auto ast = parser.parse();

  CodeGen codegen;
  std::cout << codegen.generate(ast) << std::endl;
  return 0;
}