#pragma once

#include <unordered_map>

enum class SpecialCharKind {
    Text,

    Asterisk,
    Hyphen,
    Underscore,
    Backtick,
    Hash,
    Dollar,

    OpeningAngleBracket,
    ClosingAngleBracket,
    OpeningCurlyBrace,
    ClosingCurlyBrace,
    OpeningSquareBracket,
    ClosingSquareBracket,

    Tilde, 
    Caret, 

    EOL
};

using sck = SpecialCharKind;

inline const std::unordered_map<char, sck> specialCharToKind = {
    {'*', sck::Asterisk},
    {'-', sck::Hyphen},
    {'_', sck::Underscore},
    {'`', sck::Backtick},
    {'#', sck::Hash},
    {'$', sck::Dollar},

    {'<', sck::OpeningAngleBracket},
    {'>', sck::ClosingAngleBracket},
    {'{', sck::OpeningCurlyBrace},
    {'}', sck::ClosingCurlyBrace},
    {'[', sck::OpeningSquareBracket},
    {']', sck::ClosingSquareBracket},

    {'~', sck::Tilde},
    {'^', sck::Caret},

    {'\n', sck::EOL}
};