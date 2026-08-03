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

std::string tokenToStringRepresentation(TokenType token) {
    switch (token) {
        case TokenType::Text:
            return "Text";

        case TokenType::Space:
            return "Space";

        case TokenType::HeadingMarker:
            return "HeadingMarker";
        case TokenType::Asterisk:
            return "Asterisk";
        case TokenType::Hyphen:
            return "Hyphen";
        case TokenType::Underscore:
            return "Underscore";
        case TokenType::Backtick:
            return "Backtick";
        case TokenType::Hash:
            return "Hash";
        case TokenType::DollarSign:
            return "DollarSign";

        case TokenType::OpeningSquareBracket:
            return "OpeningSquareBracket";
        case TokenType::ClosingSquareBracket:
            return "ClosingSquareBracket";
        case TokenType::OpeningCurlyBrace:
            return "OpeningCurlyBrace";
        case TokenType::ClosingCurlyBrace:
            return "ClosingCurlyBrace";
        case TokenType::OpeningAngleBracket:
            return "OpeningAngleBracket";
        case TokenType::ClosingAngleBracket:
            return "ClosingAngleBracket";

        case TokenType::Tilde:
            return "Tilde";
        case TokenType::Caret:
            return "Caret";
        
        case TokenType::BlankLine:
            return "BlankLine";
        
        case TokenType::RawText:
            return "RawText";
        
        case TokenType::EOL:
            return "EOL";
        case TokenType::Eof:
            return "EOF";

        default:
            return "Undefined";
    }
}