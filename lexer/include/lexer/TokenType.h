#pragma once

#include <string>
#include <unordered_map>

enum class TokenType {
    Text,

    HeadingMarker,

    Asterisk,
    Hyphen,
    Underscore,
    Backtick,
    Hash,
    Dollar,

    OpeningCodeSequence,
    ClosingCodeSequence,

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

inline const std::unordered_map<TokenType, std::string> tokenTypeStringRepr = {
    {TokenType::Text, "Text"},
    {TokenType::HeadingMarker, "HeadingMarker"},

    {TokenType::Asterisk, "Asterisk"},
    {TokenType::Hyphen, "Hyphen"},
    {TokenType::Underscore, "Underscore"},
    {TokenType::Backtick, "Backtick"},
    {TokenType::Hash, "Hash"},
    {TokenType::Dollar, "Dollar"},

    {TokenType::OpeningCodeSequence, "OpeningCodeSequence"},
    {TokenType::ClosingCodeSequence, "ClosingCodeSequence"},

    {TokenType::OpeningAngleBracket, "OpeningAngleBracket"},
    {TokenType::ClosingAngleBracket, "ClosingAngleBracket"},
    {TokenType::OpeningCurlyBrace, "OpeningCurlyBrace"},
    {TokenType::ClosingCurlyBrace, "ClosingCurlyBrace"},
    {TokenType::OpeningSquareBracket, "OpeningSquareBracket"},
    {TokenType::ClosingSquareBracket, "ClosingSquareBracket"},

    {TokenType::Tilde, "Tilde"},
    {TokenType::Caret, "Caret"},

    {TokenType::BlankLine, "BlankLine"},
    {TokenType::RawText, "RawText"},

    {TokenType::EOL, "EOL"},
    {TokenType::Eof, "Eof"},

    {TokenType::Undefined, "Undefined"}
};