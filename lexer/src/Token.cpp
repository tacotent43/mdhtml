#include <lexer/Token.h>

void Position::nextSymbol() {
    this->symbol += 1;
}

void Position::newLine() {
    this->symbol = 0;
    this->line += 1;
}

void Position::drop() {
    this->symbol = 0;
    this->line = 0;
}