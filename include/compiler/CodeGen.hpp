#pragma once
#include "Parser.hpp"
#include <string>

class CodeGen {
public:
  std::string generate(std::unique_ptr<ASTNode> &node);
};