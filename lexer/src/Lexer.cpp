#include <lexer/Lexer.h>

// private methods
void Lexer::updatePos() {
    if (this->rawtext[this->idx] == '\n') {
        this->pos.newLine();
        this->atLineStart = true;
    } else {
        this->pos.nextSymbol();
    }
}

bool Lexer::isAtEnd() const {
    return this->idx >= this->rawtext.size();
}

bool Lexer::isOutOfBounds(size_t offset) const {
    return (this->idx + offset) >= this->rawtext.size();
}

// public methods
explicit Lexer::Lexer(const std::string &path) {
    std::ifstream file(path, std::ios_base::in); 
    
    if (!file.is_open()) {
        throw std::runtime_error(
            Utils::getFormattedString(
                "[lexer::construct] cannot open file at {}\n", 
                path
            )
        );
    }

    std::ostringstream buff;
    buff << file.rdbuf();
    this->rawtext = buff.str();

    file.close();
}

char Lexer::peek() const {
    return this->rawtext[this->idx];
}

char Lexer::peek(size_t offset) const {
    if (this->isOutOfBounds(offset)) {
        throw std::out_of_range(
            Utils::getFormattedString(
                "[lexer::peek()] cannot peek symbol with offset {}: index out of range (curr {}, tried {}, max {})",
                offset, this->idx, this->idx + offset, this->rawtext.size()
            )
        );
    }
}

char Lexer::next() {
    if (this->isAtEnd()) {
        throw std::out_of_range(
            Utils::getFormattedString(
                "[lexer::next()] cannot get next symbol: index out of range (curr {}, tried {}, max {})",
                this->idx, this->idx + 1, this->rawtext.size()
            )
        );
    }
    this->updatePos();
    return this->rawtext[this->idx++];
}

Token Lexer::nextToken() {
    if (this->isAtEnd()) {
        return Token(
            TokenType::Eof, 
            this->pos
        );
    }

}

void Lexer::tokenize() {

}