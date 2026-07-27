#include <lexer/SourceCursor.h>

explicit SourceCursor::SourceCursor(const std::string &path) {
    std::ifstream file(path, std::ios_base::in);
    
    if (!file.is_open()) {
        throw std::runtime_error(
            Utils::getFormattedString(
                "[Lexer::SourceCursor::constructor] cannot open file at {}\n",
                path
            )
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
        throw std::out_of_range(
            Utils::getFormattedString(
                "[Lexer::SourceCursor::operator++] canot get next symbol: index out of range (curr {}, tried {}, max {})",
                this->idx, this->idx + 1, this->rawtext.size()
            )
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

char SourceCursor::peek() const {
    return this->rawtext[this->idx];
}

char SourceCursor::peek(size_t offset) const {
    if (this->isOutOfBounds(offset)) {
        throw std::out_of_range(
            Utils::getFormattedString(
                "[lexer::SourceCursor::peek()] cannot peeek symbol with offset {}:",
                offset, this->idx, this->idx + offset, this->rawtext.size()
            )
        );
    }
    return this->rawtext[this->idx + offset];
}

char SourceCursor::next() {
    if (this->isAtEnd()) {
        throw std::out_of_range(
            Utils::getFormattedString(
                "[Lexer::SourceCursor::next()] canot get next symbol: index out of range (curr {}, tried {}, max {})",
                this->idx, this->idx + 1, this->rawtext.size()
            )
        );
    }
    this->operator++();
    return this->rawtext[this->idx - 1];
}