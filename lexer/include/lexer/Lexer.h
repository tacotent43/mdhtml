#pragma once

#include <lexer/Token.h>
#include <utils/FormatString.h>

#include <fstream>
#include <sstream>

enum class LexerMode {
    regular, 
    raw
};

class Lexer {
private: // fields
    std::string rawtext;

    std::vector<Token> tokens;

    size_t idx = 0;
    bool atLineStart = true;

    Position pos;

    LexerMode mode = LexerMode::regular;

private: // methods
    void updatePos();

    bool isAtEnd() const;

    bool isOutOfBounds(size_t offset) const;

public:
    explicit Lexer(const std::string &path);

    char peek() const;
    char peek(size_t offset) const;

    char next();

    Token nextToken();
    void tokenize();

    ~Lexer() = default;
};