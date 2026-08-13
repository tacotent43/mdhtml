#include <iostream>
#include <lexer/Lexer.h>

int main() {
    Lexer lexer = Lexer("llvm-config-odin.md");

    lexer.tokenize();

    return 0;
}