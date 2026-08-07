#pragma once

#include <lexer/Position.h>
#include <utils/FormatString.h>
#include <utils/Exceptions.h>

#include <string>
#include <fstream>
#include <sstream>
#include <source_location>

struct SourceCursor {
    std::string rawtext;

    // index with current position in raw text
    size_t idx = static_cast<size_t>(0);
    Position pos;

    bool atLineStart = true;

    explicit SourceCursor(const std::string &path);
    
    bool isAtEnd() const;
    bool isOutOfBounds(size_t offset) const;

    char peek() const;
    char peek(size_t offset) const;
    char peekNext() const;
    std::string peekNextN(size_t N) const;

    char next();
};