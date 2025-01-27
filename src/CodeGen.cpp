#include "compiler/CodeGen.hpp"
#include <sstream>

std::string CodeGen::generate(std::unique_ptr<ASTNode> &node) {
  std::stringstream asmCode;
  asmCode << "section .text\n"
          << "global _start\n"
          << "_start:\n";

  // TODO: Traverse AST and emit assembly
  // Example for 2 + 3 * 4:
  asmCode << "  mov eax, 3\n"
          << "  imul eax, 4\n"
          << "  add eax, 2\n"
          << "  mov ebx, eax\n"
          << "  mov eax, 1\n"    // sys_exit
          << "  int 0x80\n";
  return asmCode.str();
}