#pragma once

#include <lexer/Position.h>
#include <utils/FormatString.h>

#include <string>
#include <fstream>
#include <sstream>

struct SourceCursor {
    std::string rawtext;

    // index with current position in raw text
    size_t idx = static_cast<size_t>(0);
    Position pos;

    bool atLineStart = true;

    SourceCursor() {}
    explicit SourceCursor(const std::string &path);
    
    bool isAtEnd() const;
    bool isOutOfBounds(size_t offset) const;

private:
    SourceCursor& operator++();
    SourceCursor operator++(int);

public:
    std::string peekNextN(size_t N);

    char peek() const;
    char peek(size_t offset) const;

    char next();
};