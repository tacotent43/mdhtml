#include <lexer/Lexer.h>

explicit Lexer::Lexer(const std::string &path) {
    this->source = SourceCursor(path);
}

// private methods
Token Lexer::atEnd() {
    return Token(
        TokenType::Eof,
        this->source.pos
    );
}

Token Lexer::readRawText() {
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

// public methods
Token Lexer::nextToken() {
    // End of file
    if (this->source.isAtEnd()) {
        return this->atEnd();
    }

    // Raw-mode for code blocks
    if (this->mode == LexerMode::raw) {
        return this->readRawText();
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
    if (this->source.peek().classify() == sck::Text) {
        std::string value;
        
        while (
            this->source.peek().classify() == sck::Text ||
            this->source.peek().classify() == sck::Space
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
    if (this->source.peek().classify() == sck::EOL) {
        return Token(
            TokenType::EOL,
            this->source.pos, 
            std::string(1, this->source.next())
        );
    }

    // Asterisk
    if (this->source.peek().classify() == sck::Asterisk) {
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
    if (this->source.peek().classify() == sck::Underscore) {
        std::string value = "";

        // collecting
        while (this->source.peek().classify() == sck::Underscore) {
            value.push_back(this->source.next());
        }

        // 
        if (this->source.peek().classify() == sck::Space) {
            return Token(
                TokenType::Text,
                this->source.pos,
                std::string(1, this->source.next())
            );
        }
        
        // underscore means italic/bold/italic+bold
        std::string value = "";
        Position pos = this->source.pos;

        while (this->source.peek().classify() == sck::Underscore) {
            value.push_back(this->source.next());
        }

        return Token(
            TokenType::Underscore,
            pos, value
        );
    }

    // Backtick
    if (this->source.peek().classify() == sck::Backtick) {
        std::string value = "";
        
        // TODO: implement
    }

    // Hash
    if (this->source.peek().classify() == sck::Hash) {
        bool isHeading = true;
        std::string value = "";
        Position pos = this->source.pos;

        if (this->source.atLineStart) {
            if (
                this->source.peekNext().classify() == sck::Hash ||
                this->source.peekNext().classify() == sck::Space
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
            while (this->source.peek().classify() == sck::Hash) {
                value.push_back(this->source.next());
            }

            return Token(
                TokenType::HeadingMarker,
                pos, value
            );
        }

        // hash means tag
        while(this->source.peek().classify() != sck::Space) {
            value.push_back(this->source.next());
        }

        return Token(
            TokenType::Hash,
            pos, value
        );
    }

    // Dollar Sign
    if (this->source.peek().classify() == sck::Dollar) {
        std::string value = "";
        Position pos;

        // collecting
        while (this->source.peek().classify() == sck::Dollar) {
            value.push_back(this->source.next());
        }
        
        size_t dollarSequenceLength = value.size();

        // Dollar Sign means nothing
        if (this->source.peekNext().classify() == sck::Space) {
            return Token(
                TokenType::Text,
                pos, value
            );
        }

        // Dollar Sign means start of LaTeX sequence
        while (this->source.peek().classify() != sck::Dollar) {
            value.push_back(this->source.next());
        }

        if (isOpeningSingleSequence) {
            
        }

        // TODO: implement
    }

    // Opening Angle Bracket
    if (this->source.peek().classify() == sck::OpeningAngleBracket) {
        // TODO: implement
    }

    // Closing Angle Bracket
    if (this->source.peek().classify() == sck::ClosingAngleBracket) {
        // TODO: implement
    }

    // Opening Curly Brace
    if (this->source.peek().classify() == sck::OpeningCurlyBrace) {
        // TODO: implement
    }

    // Closing Curly Brace
    if (this->source.peek().classify() == sck::ClosingCurlyBrace) {
        // TODO: implement
    }

    // Opening Square Bracket
    if (this->source.peek().classify() == sck::OpeningSquareBracket) {
        // TODO: implement
    }

    // Closing Square Bracket
    if (this->source.peek().classify() == sck::ClosingSquareBracket) {
        // TODO: implement
    }

    // Tilde
    if (this->source.peek().classify() == sck::Tilde) {
        // TODO: implement
    }

    // Caret
    if (this->source.peek().classify() == sck::Caret) {
        // TODO: implement
    }

    // BlankLine
    if (this->source.peek().classify() == sck::BlankLine) {
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
