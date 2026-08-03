#pragma once

#include <string>

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

    OpeningSquareBracket,
    ClosingSquareBracket,
    OpeningCurlyBrace,
    ClosingCurlyBrace,
    OpeningAngleBracket,
    ClosingAngleBracket,

    Tilde, 
    Caret, 

    BlankLine,

    RawText,

    EOL,
    Eof, 
    
    Undefined
};

TokenType getTokenBySymbol(char c);
std::string tokenToStringRepresentation(TokenType token);