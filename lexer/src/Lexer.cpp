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
        
        // hard-coded value
        while (!(this->source.peekNextN(3) == "```" && this->source.atLineStart)) {
            try {
                codeblock.value.push_back(this->source.next());
            } catch (const std::exception &e) {
                // throw something here
                // throw std::
            }
        }

        return codeblock;
    }

    if (this->source.atLineStart) {
        
    }
}

void Lexer::tokenize() {
    // TODO: implement
}