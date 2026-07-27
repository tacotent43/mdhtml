#include <lexer/Lexer.h>

explicit Lexer::Lexer(const std::string &path) {
    this->source = SourceCursor(path);
}

Token Lexer::nextToken() {
    // TODO: implement
    if (this->source.isAtEnd()) {
        return Token(
            TokenType::Eof,
            this->source.pos
        );
    }

    if (this->mode == LexerMode::raw) {
        Token codeblock;
        while (getTokenBySymbol(this->source.peek()) == TokenType::Text) {
            codeblock.value.push_back(this->source.peek());
        }
    }

    if (this->source.atLineStart) {
        
    }
}

void Lexer::tokenize() {
    // TODO: implement
}