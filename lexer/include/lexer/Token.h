#pragma once

#include <iostream>
#include <string>
#include <lexer/Position.h>
#include <lexer/TokenType.h>
#include <utils/ShortenString.h>

struct Token {
    TokenType type;
    std::string value;
    Position position;

    Token() : type(TokenType::Undefined), value(""), position(Position()) {}
    explicit Token(TokenType type, Position position, std::string value = "") : type(type), value(value), position(position) {}

    std::string repr() const;
    std::string fullRepr() const;

    ~Token() = default;
};