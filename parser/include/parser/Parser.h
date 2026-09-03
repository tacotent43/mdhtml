#pragma once

#include <vector>
#include <source_location>

#include <lexer/Lexer.h>

class Parser {
    std::vector<Token> tokens;
    size_t idx = 0;

    bool isAtEnd() const;

public:
    Token peek() const;
    Token next();
    bool check(TokenType type) const;
    void expect(TokenType type);
};