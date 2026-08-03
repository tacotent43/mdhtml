#include <lexer/Lexer.h>

explicit Lexer::Lexer(const std::string &path) {
    this->source = SourceCursor(path);
}

Token Lexer::nextToken() {
    if (this->source.isAtEnd()) {
        return Token(
            TokenType::Eof,
            this->source.pos
        );
    }

    if (this->mode == LexerMode::raw) {
        Token codeblock;
        const std::string closingFence = std::string(this->fenceLength, this->fenceChar);

        codeblock.type = TokenType::RawText;
        codeblock.position = this->source.pos;
        
        while (
            !(this->source.peekNextN(this->fenceLength) == closingFence && this->source.atLineStart)
        ) {
            if (this->source.isAtEnd()) {
                Utils::throwException<std::exception>(
                    std::source_location::current(),
                    "did not found closing codefence symbols \'{}\' at least {} times until EOF",
                    this->fenceChar, this->fenceLength
                );
            }
            codeblock.value.push_back(this->source.next());
        }

        return codeblock;
    }

    if (this->source.atLineStart) {
        
    }
}

void Lexer::tokenize() {
    // TODO: implement
}