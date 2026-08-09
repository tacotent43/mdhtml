#pragma once

#include <lexer/SpecialCharKind.h>

struct ClassifiedChar {
    char c = '\0';
    SpecialCharKind classify();

    ClassifiedChar() : c('\0') {}
    ClassifiedChar(char c) : c(c) {}
};