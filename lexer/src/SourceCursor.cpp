#include <lexer/SourceCursor.h>

SourceCursor::SourceCursor() {}

SourceCursor::SourceCursor(const std::string &path) {
    std::ifstream file(path, std::ios_base::in);
    
    if (!file.is_open()) {
        Utils::throwException<std::runtime_error>(
            std::source_location::current(),
            "cannot open file at {}",
            path
        );
    }
    
    std::ostringstream buff;
    buff << file.rdbuf();
    this->rawtext = buff.str();

    file.close();
}

/*
Returns `true` when current index is greater or equal to length of source text.
*/
bool SourceCursor::isAtEnd() const {
    return this->idx >= this->rawtext.size();
}

/*
Returns `true` when current index with `size_t offset` is greater or equal to length of source text.
*/
bool SourceCursor::isOutOfBounds(size_t offset) const {
    return (this->idx + offset) >= this->rawtext.size();
}

/* 
Returns current character
*/
ClassifiedChar SourceCursor::peek() const {
    return this->rawtext[this->idx];
}

/* 
Returns character, which is `size_t offset` positions after current.

Throws `std::out_of_range` exception.
*/
ClassifiedChar SourceCursor::peek(size_t offset) const {
    if (this->idx + offset > this->rawtext.size()) {
        Utils::throwException<std::out_of_range>(
            std::source_location::current(),
            "cannot peek symbol with offset {} @ idx {} | tried {}, max {}: index out of range",
            offset, this->idx, this->idx + offset, this->rawtext.size()
        );
    }
    if (this->isOutOfBounds(offset)) {
        return '\0';
    }
    return this->rawtext[this->idx + offset];
}

/*
Returns next character after current.

Throw `std::out_of_range` exception.
*/
ClassifiedChar SourceCursor::peekNext() const {
    return this->peek(1);
}

/*
Peeks and merges all characters in range of `N` symbols.
*/
std::string SourceCursor::peekNextN(size_t N) const {
    std::string symbols;
    size_t end = std::min(idx + N, this->rawtext.size());
    for (size_t i = idx; i < end; ++i) {
        symbols.push_back(this->rawtext[i]);
    }
    return symbols;
}

/*
Returns current character, then jumps to next.

// Throws `std::out_of_range` exception.
*/
ClassifiedChar SourceCursor::next() {
    if (this->isAtEnd()) {
        return '\0';
    }
    if (this->rawtext[idx] == '\n') {
        this->pos.newLine();
        this->atLineStart = true;
    } else {
        this->pos.nextSymbol();
        if (this->rawtext[idx + 1]) {
            
        }
        this->atLineStart = false;
    }
    idx++;
    return this->rawtext[this->idx - 1];
}