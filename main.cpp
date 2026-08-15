#include <iostream>
#include <lexer/Lexer.h>

int main() {
    // Lexer lexer = Lexer("../hello.md");
    Lexer lexer = Lexer("hello-1.md"); 

    lexer.tokenize();

    lexer.repr();

    return 0;
}