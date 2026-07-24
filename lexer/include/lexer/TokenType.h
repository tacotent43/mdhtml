#pragma once

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

    EOL,
    Eof
};

TokenType getTokenBySymbol(char c);