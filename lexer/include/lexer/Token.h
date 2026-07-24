#pragma once

#include <iostream>
#include <string>
#include <lexer/TokenType.h>

struct Position {
    unsigned int symbol;
    unsigned int line;

    Position() : symbol(0), line(0) {}
    explicit Position(unsigned int symbol, unsigned int line) : symbol(symbol), line(line) {}

    void nextSymbol();
    void newLine();
    void drop();

    ~Position() = default;
};

struct Token {
    TokenType type;
    std::string value;
    Position position;

    explicit Token(TokenType type, Position position, std::string value = "") : type(type), value(value), position(position) {}
};