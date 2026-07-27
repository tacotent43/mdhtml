#pragma once

#include <lexer/Token.h>
#include <lexer/Position.h>
#include <lexer/SourceCursor.h>
#include <utils/FormatString.h>

#include <fstream>
#include <sstream>

enum class LexerMode {
    regular, 
    raw
};

class Lexer {
private: // fields
    std::vector<Token> tokens;

    SourceCursor source;

    LexerMode mode = LexerMode::regular;

public:
    explicit Lexer(const std::string &path);

    Token nextToken();
    void tokenize();

    ~Lexer() = default;
};