#pragma once

#include <iostream>
#include <string>
#include <lexer/TokenType.h>

struct Token {
    TokenType type;
    std::string value;
    Position position;

    Token() {}
    explicit Token(TokenType type, Position position, std::string value = "") : type(type), value(value), position(position) {}
};