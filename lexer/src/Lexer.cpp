#include <lexer/Lexer.h>

explicit Lexer::Lexer(const std::string &path) {
    this->source = SourceCursor(path);
}

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

    // At the beginning of the line
    if (this->source.atLineStart) {
        if (this->source.peekNextN(3) == "~~~" || this->source.peekNextN(3) == "```") {
            this->fenceChar = this->source.peek();
            this->fenceLength = 3;
            this->fenceStartIdx = this->source.idx;

            for (int i = 0; i < 3; ++i) {
                this->source.next();
            }
            
            for (;;) {
                if (this->source.peek() != this->fenceChar) {
                    this->source.next();
                    break;
                }
                this->fenceLength++;
            }

            this->mode = LexerMode::raw;
            return Token();
        }
    }

    // Normal mode
    if (getTokenBySymbol(this->source.peek()) == TokenType::Text) {
        std::string value;
        
        while (
            getTokenBySymbol(this->source.peek()) == TokenType::Text ||
            getTokenBySymbol(this->source.peek()) == TokenType::Space
        ) {
            value.push_back(this->source.next());
        }
        
        return Token(
            TokenType::Text,
            this->source.pos,
            value
        );
    }

    // End of line
    if (getTokenBySymbol(this->source.peek()) == TokenType::EOL) {
        return Token(
            TokenType::EOL,
            this->source.pos, 
            std::string(1, this->source.next())
        );
    }

    // Asterisk
    if (getTokenBySymbol(this->source.peek()) == TokenType::Asterisk) {
        bool isListItem = true;
        std::string value = "";
        
        // etc.

        // Asterisk means a member of list

        // return Token(
        //     TokenType::Asterisk,
        //     this->source.pos,

        // );
    }

    // Underscore
    if (getTokenBySymbol(this->source.peek()) == TokenType::Underscore) {
        if (getTokenBySymbol(this->source.peekNext()) == TokenType::Space) {
            return Token(
                TokenType::Text,
                this->source.pos,
                std::string(1, this->source.next())
            );
        }
        
        // underscore means italic/bold/italic+bold
        std::string value = "";
        Position pos = this->source.pos;

        while (getTokenBySymbol(this->source.peekNext()) == TokenType::Underscore) {
            value.push_back(this->source.next());
        }

        return Token(
            TokenType::Underscore,
            pos, value
        );
    }

    // Backtick
    if (getTokenBySymbol(this->source.peek()) == TokenType::Backtick) {
        std::string value = "";
        
        // TODO: implement
    }


    // Hash
    if (getTokenBySymbol(this->source.peek()) == TokenType::Hash) {
        bool isHeading = true;
        std::string value = "";
        Position pos = this->source.pos;

        if (this->source.atLineStart) {
            if (
                getTokenBySymbol(this->source.peekNext()) == TokenType::Hash ||
                getTokenBySymbol(this->source.peekNext()) == TokenType::Space
            ) {
                isHeading = true;
            } else {
                isHeading = false;
            }
        } else {
            isHeading = false;
        }

        // hash means heading
        if (isHeading) {
            while (getTokenBySymbol(this->source.peek()) == TokenType::Hash) {
                value.push_back(this->source.next());
            }

            return Token(
                TokenType::HeadingMarker,
                pos, value
            );
        }
        // hash means tag
        while(getTokenBySymbol(this->source.peek()) != TokenType::Space) {
            value.push_back(this->source.next());
        }

        return Token(
            TokenType::Hash,
            pos, value
        );
    }

    // Dollar Sign
    if (getTokenBySymbol(this->source.peek()) == TokenType::DollarSign) {
        std::string value = "";

        // collecting
        while (getTokenBySymbol(this->source.peek()))

        if (getTokenBySymbol(this->source.peekNext()) == TokenType::Space) {
            
        }

        // TODO: implement
    }

    // Opening Angle Bracket
    if (getTokenBySymbol(this->source.peek()) == TokenType::OpeningAngleBracket) {
        // TODO: implement
    }

    // Closing Angle Bracket
    if (getTokenBySymbol(this->source.peek()) == TokenType::ClosingAngleBracket) {
        // TODO: implement
    }

    // Opening Curly Brace
    if (getTokenBySymbol(this->source.peek()) == TokenType::OpeningCurlyBrace) {
        // TODO: implement
    }

    // Closing Curly Brace
    if (getTokenBySymbol(this->source.peek()) == TokenType::ClosingCurlyBrace) {
        // TODO: implement
    }

    // Opening Square Bracket
    if (getTokenBySymbol(this->source.peek()) == TokenType::OpeningSquareBracket) {
        // TODO: implement
    }

    // Closing Square Bracket
    if (getTokenBySymbol(this->source.peek()) == TokenType::ClosingSquareBracket) {
        // TODO: implement
    }

    // Tilde
    if (getTokenBySymbol(this->source.peek()) == TokenType::Tilde) {
        // TODO: implement
    }

    // Caret
    if (getTokenBySymbol(this->source.peek()) == TokenType::Caret) {
        // TODO: implement
    }

    // BlankLine
    if (getTokenBySymbol(this->source.peek()) == TokenType::BlankLine) {
        // TODO: implement
    }

    this->source.next();
    return Token(
        TokenType::Undefined,
        this->source.pos
    );
}

void Lexer::tokenize() {
    // TODO: implement
}
