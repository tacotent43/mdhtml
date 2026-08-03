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

bool SourceCursor::isAtEnd() const {
    return this->idx >= this->rawtext.size();
}

bool SourceCursor::isOutOfBounds(size_t offset) const {
    return (this->idx + offset) >= this->rawtext.size();
}

SourceCursor& SourceCursor::operator++() {
    if (this->isAtEnd()) {
        Utils::throwException<std::out_of_range>(
            std::source_location::current(),
            "index out of range @ {} | tried {}, max {}: cannot get next symbol",
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
    return *this;
}

SourceCursor SourceCursor::operator++(int) {
    SourceCursor old = *this;
    this->operator++();
    return old;
}

std::string SourceCursor::peekNextN(size_t N) {
    std::string symbols;
    for (size_t i = idx + 1; i <= idx + N; ++i) {
        if (isOutOfBounds(3)) {
            Utils::throwException<std::out_of_range>(
                std::source_location::current(),
                "cannot find closing code fence sequence @ {}-{}: found EOF",
                this->idx, this->idx + 3
            );
        }
        symbols.push_back(this->rawtext[i]);
    }
    return symbols;
}

char SourceCursor::peek() const {
    return this->rawtext[this->idx];
}

char SourceCursor::peek(size_t offset) const {
    if (this->isOutOfBounds(offset)) {
        Utils::throwException<std::out_of_range>(
            std::source_location::current(),
            "cannot peek symbol with offset {} @ idx {} | tried {}, max {}: index out of range",
            offset, this->idx, this->idx + offset, this->rawtext.size()
        );
    }
    return this->rawtext[this->idx + offset];
}

char SourceCursor::next() {
    if (this->isAtEnd()) {
        Utils::throwException<std::out_of_range>(
            std::source_location::current(),
            "cannok get next symbol at @ idx {} | tried {}, max {}: index out of range", 
            this->idx, this->idx + 1, this->rawtext.size()
        );
    }
    this->operator++();
    return this->rawtext[this->idx - 1];
}