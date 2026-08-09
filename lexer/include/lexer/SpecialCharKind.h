#pragma once

#include <unordered_map>

enum class SpecialCharKind {
    Text,

    Space,
    
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

    EOL
};

using sck = SpecialCharKind;

static const std::unordered_map<char, sck> specialCharToKind = {
    {' ', sck::Space},

    {'*', sck::Asterisk},
    {' ', sck::Hyphen},
    {'_', sck::Underscore},
    {'`', sck::Backtick},
    {'#', sck::Hash},
    {'$', sck::DollarSign},

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