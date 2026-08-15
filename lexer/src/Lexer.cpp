#include <lexer/Lexer.h>

Lexer::Lexer(const std::string &path) {
    this->source = SourceCursor(path);
}

// private method
Token Lexer::collectSymbolsToToken(const sck &charkind, const TokenType &tokentype) {
    std::string value = "";
    Position pos = this->source.pos;

    while (this->source.peek().classify() == charkind) {
        value.push_back(this->source.next());
    }

    return Token(tokentype, pos, value);
}

// public methods
Token Lexer::nextToken() {
    // End of file
    if (this->source.isAtEnd()) {
        return Token(
            TokenType::Eof,
            this->source.pos
        );
    }

    // Raw-mode for code blocks
    if (this->mode == LexerMode::raw) {
        Token codeblock;
        const std::string closingFence = std::string(this->fenceLength, this->fenceChar);

        codeblock.type = TokenType::RawText;
        codeblock.position = this->source.pos;
        
        for (;;) {
            if (this->source.isOutOfBounds(this->fenceLength)) {
                // [debug]
                for (auto token : this->tokens) {
                    std::cerr << token.repr(0) << '\n';
                }

                Utils::throwException<std::out_of_range>(
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

    // At the beginning of the line
    if (this->source.atLineStart) {
        if (this->source.peekNextN(3) == "~~~" || this->source.peekNextN(3) == "```") {
            std::string value = "";
            Position pos = this->source.pos;

            this->fenceChar = this->source.peek();
            this->fenceLength = 0;
            this->fenceStartIdx = this->source.idx;

            while (this->source.peek() == this->fenceChar) {
                value.push_back(this->source.next());
                this->fenceLength++;
            }

            // latest token was raw text - current token is NOT the opening sequence
            if (this->tokens[this->tokens.size() - 1].type == TokenType::RawText) {
                return Token(
                    TokenType::ClosingCodeSequence,
                    pos, value
                );
            }

            this->mode = LexerMode::raw;
            return Token(
                TokenType::OpeningCodeSequence,
                pos, value
            );
        }
    }

    // Normal mode
    if (this->source.peek().classify() == sck::Text) {
        return this->collectSymbolsToToken(sck::Text, TokenType::Text);
    }

    // End of line
    if (this->source.peek().classify() == sck::EOL) {
        return Token(
            TokenType::EOL,
            this->source.pos, 
            std::string(1, this->source.next())
        );
    }

    // Asterisk
    if (this->source.peek().classify() == sck::Asterisk) {
        return this->collectSymbolsToToken(sck::Asterisk, TokenType::Asterisk);
    }

    // Underscore
    if (this->source.peek().classify() == sck::Underscore) {
        return this->collectSymbolsToToken(sck::Underscore, TokenType::Underscore);
    }

    // Backtick
    if (this->source.peek().classify() == sck::Backtick) {
        return this->collectSymbolsToToken(sck::Backtick, TokenType::Backtick);
    }

    // Hash
    if (this->source.peek().classify() == sck::Hash) {
        return this->collectSymbolsToToken(sck::Hash, TokenType::Hash);
    }

    // Dollar Sign
    if (this->source.peek().classify() == sck::Dollar) {
        return this->collectSymbolsToToken(sck::Dollar, TokenType::Dollar);
    }

    // Opening Angle Bracket
    if (this->source.peek().classify() == sck::OpeningAngleBracket) {
        return this->collectSymbolsToToken(sck::OpeningAngleBracket, TokenType::OpeningAngleBracket);
    }

    // Closing Angle Bracket
    if (this->source.peek().classify() == sck::ClosingAngleBracket) {
        return this->collectSymbolsToToken(sck::ClosingAngleBracket, TokenType::ClosingAngleBracket);
    }

    // Opening Curly Brace
    if (this->source.peek().classify() == sck::OpeningCurlyBrace) {
        return this->collectSymbolsToToken(sck::OpeningCurlyBrace, TokenType::OpeningCurlyBrace);
    }

    // Closing Curly Brace
    if (this->source.peek().classify() == sck::ClosingCurlyBrace) {
        return this->collectSymbolsToToken(sck::ClosingCurlyBrace, TokenType::ClosingCurlyBrace);
    }

    // Opening Square Bracket
    if (this->source.peek().classify() == sck::OpeningSquareBracket) {
        return this->collectSymbolsToToken(sck::OpeningSquareBracket, TokenType::OpeningSquareBracket);
    }

    // Closing Square Bracket
    if (this->source.peek().classify() == sck::ClosingSquareBracket) {
        return this->collectSymbolsToToken(sck::ClosingSquareBracket, TokenType::ClosingSquareBracket);
    }

    // Tilde
    if (this->source.peek().classify() == sck::Tilde) {
        return this->collectSymbolsToToken(sck::Tilde, TokenType::Tilde);
    }

    // Caret
    if (this->source.peek().classify() == sck::Caret) {
        return this->collectSymbolsToToken(sck::Caret, TokenType::Caret);
    }

    this->source.next();
    return Token(
        TokenType::Undefined,
        this->source.pos
    );
}

void Lexer::tokenize() {
    for (;;) {
        Token token = this->nextToken();
        this->tokens.push_back(token);

        if (token.type == TokenType::Eof) {
            break;
        }
    }
}

void Lexer::repr() const {
    for (const Token &token : this->tokens) {
        std::cerr << token.repr(0) << '\n';
    }
}
