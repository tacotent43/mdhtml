#pragma once

#include <lexer/Token.h>
#include <lexer/Position.h>
#include <lexer/SourceCursor.h>
#include <utils/FormatString.h>
#include <utils/Exceptions.h>

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

    // code fence
    std::string fenceLang = "haskell";
    char fenceChar = '`';
    size_t fenceLength = 0;
    size_t fenceStartIdx = 0;

    LexerMode mode = LexerMode::regular;

private: // methods
    Token atEnd();
    Token readRawText();


public:
    explicit Lexer(const std::string &path);

    Token nextToken();
    void tokenize();

    ~Lexer() = default;
};