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
        
        for (;;) {
            if (this->source.isOutOfBounds(this->fenceLength)) {
                Utils::throwException<std::exception>(
                    std::source_location::current(),
                    "did not found closing codefence symbols \'{}\' at least {} times until EOF",
                    this->fenceChar, this->fenceLength
                );
            }

            if (this->source.peekNextN(this->fenceLength) == closingFence && this->source.atLineStart) {
                break;
            }

            codeblock.value.push_back(this->source.next());
        }

        this->mode = LexerMode::regular;

        return codeblock;
    }

    if (this->source.atLineStart) {
        // TODO: refactor
        if (this->source.peekNextN(3) == "~~~" || this->source.peekNextN(3) == "```") {
            this->fenceChar = this->source.peek();
            this->fenceLength = 3;
            this->fenceStartIdx = this->source.idx;

            for (int i = 0; i < 3; ++i) {
                this->source.next();
            }
            
            for (;;) {
                if (this->source.next() != this->fenceChar) {
                    break;
                }
                this->fenceLength++;
            }

            this->mode = LexerMode::raw;
            return Token()
        }
    }

    // Normal mode
    if (getTokenBySymbol(this->source.peek()) == TokenType::Text) {
        std::string value;
        while (getTokenBySymbol(this->source.peek()) == TokenType::Text) {
            value.push_back(this->source.next());
        }
        this->tokens.push_back(
            Token(
                TokenType::Text,
                this->source.pos,
                value
            )
        );
    }

    while (getTokenBySymbol(this->source.peek()) == TokenType::Hash) {
        
    }
}

void Lexer::tokenize() {
    // TODO: implement
}