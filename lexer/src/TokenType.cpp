#include <lexer/TokenType.h>

TokenType getTokenBySymbol(char c) {
    switch (c) {
    case ' ': 
        return TokenType::Space;
    
    case '#':
        return TokenType::Hash;
    
    case '*':
        return TokenType::Asterisk;
    case '-':
        return TokenType::Hyphen;
    case '_':
        return TokenType::Underscore;
    case '`':
        return TokenType::Backtick;
    case '$':
        return TokenType::DollarSign;

    case '[':
        return TokenType::OpeningSquareBracket;
    case ']':
        return TokenType::ClosingSquareBracket;

    case '{':
        return TokenType::OpeningCurlyBrace;
    case '}':
        return TokenType::ClosingCurlyBrace;
    
    case '<':
        return TokenType::OpeningAngleBracket;
    case '>':
        return TokenType::ClosingAngleBracket;
    
    case '~':
        return TokenType::Tilde;
    case '^': 
        return TokenType::Caret;

    case '\n':
        return TokenType::EOL;

    default:
        return TokenType::Text;
    }
}