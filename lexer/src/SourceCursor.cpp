#include <lexer/SourceCursor.h>

explicit SourceCursor::SourceCursor(const std::string &path) {
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
    if (this->isOutOfBounds(offset)) {
        Utils::throwException<std::out_of_range>(
            std::source_location::current(),
            "cannot peek symbol with offset {} @ idx {} | tried {}, max {}: index out of range",
            offset, this->idx, this->idx + offset, this->rawtext.size()
        );
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

Throws `std::out_of_range` exception.
*/
std::string SourceCursor::peekNextN(size_t N) const {
    std::string symbols;
    if (isOutOfBounds(N)) {
        Utils::throwException<std::out_of_range>(
            std::source_location::current(),
            "cannot peek next N-symbols sequence @ {}-{}: found EOF",
            this->idx, this->idx + N
        );
    }
    for (size_t i = idx; i < idx + N; ++i) {
        symbols.push_back(this->rawtext[i]);
    }
    return symbols;
}

/*
Returns current character, then jumps to next.

Throws `std::out_of_range` exception.
*/
ClassifiedChar SourceCursor::next() {
    if (this->isAtEnd()) {
        Utils::throwException<std::out_of_range>(
            std::source_location::current(),
            "cannot get next symbol at @ idx {} | tried {}, max {}: index out of range", 
            this->idx, this->idx + 1, this->rawtext.size()
        );
    }
    if (this->rawtext[idx] == '\n') {
        this->pos.newLine();
        this->atLineStart = true;
    } else {
        this->pos.nextSymbol();
    }
    idx++;
    return this->rawtext[this->idx - 1];
}