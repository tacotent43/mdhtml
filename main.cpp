#include <iostream>
#include <lexer/Lexer.h>

int main() {
    Lexer lexer = Lexer("../hello.md");

    lexer.tokenize();

    lexer.repr();

    return 0;
}