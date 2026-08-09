#pragma once

#include <string>
#include <unordered_map>

enum class TokenType {
    Text,

    Space,
    
    HeadingMarker,

    Asterisk,
    Hyphen,
    Underscore,
    Backtick,
    Hash,
    DollarSign,

    OpeningAngleBracket,
    ClosingAngleBracket,
    OpeningCurlyBrace,
    ClosingCurlyBrace,
    OpeningSquareBracket,
    ClosingSquareBracket,

    Tilde, 
    Caret, 

    BlankLine,

    RawText,

    EOL,
    Eof,
    
    Undefined
};

std::unordered_map<TokenType, char> TokenTypeChar = {
    
};

TokenType getTokenBySymbol(char c);
std::string tokenToStringRepresentation(TokenType token);