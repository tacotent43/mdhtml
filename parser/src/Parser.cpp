#include <parser/Parser.h>

// private
bool Parser::isAtEnd() const {
    return this->idx >= this->tokens.size() || 
           this->tokens[this->idx].type == TokenType::Eof; 
}

// public
Token Parser::peek() const {
    if (this->isAtEnd()) {
        Utils::throwException<std::out_of_range>(
            std::source_location::current(),
            "cannot peek token @ idx {} | tried {}, max {}: index out of range",
            this->idx, this->idx, this->tokens.size()
        );
    }
    return this->tokens[this->idx];
}

Token Parser::next() {
    if (this->isAtEnd()) {
        Utils::throwException<std::out_of_range>(
            std::source_location::current(),
            "cannot move index further @ idx {} | tried {}, max {}: index out of range",
            this->idx, this->idx + 1, this->tokens.size()
        );
    }
    return this->tokens[this->idx++];
}

bool Parser::check(TokenType type) const {
    return static_cast<bool>(this->tokens[this->idx].type == type);
}

void Parser::expect(TokenType type) {
    if (this->tokens[this->idx].type != type) {
        Utils::throwException<std::runtime_error>(
            std::source_location::current(),
            "expected token \"Token::{}\", found \"{}\"",
            tokenTypeStringRepr.at(type), this->tokens[this->idx].repr()
        );
    }
    if (this->isAtEnd()) {
        Utils::throwException<std::out_of_range>(
            std::source_location::current(),
            "cannot move index further @ idx {} | tried {}, max {}: index out of range",
            this->idx, this->idx + 1, this->tokens.size()
        );
    }
    this->idx++;
}