#pragma once

#include <lexer/SpecialCharKind.h>

struct ClassifiedChar {
    char c = '\0';
    SpecialCharKind classify();

    ClassifiedChar() = default;
    ClassifiedChar(char c) : c(c) {}
    
    operator char() const {
        return this->c;
    }

    ClassifiedChar& operator=(char c) {
        this->c = c;
        return *this;
    }
};