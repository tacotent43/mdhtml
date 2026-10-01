#include <parser/Parser.h>

// private
bool Parser::isAtEnd() const {
    return this->idx >= this->tokens.size() || 
           this->tokens[this->idx].type == TokenType::Eof; 
}

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

bool Parser::checkCurrentTokenType(TokenType type) const {
    return static_cast<bool>(this->peek().type == type);
}

void Parser::assert(TokenType type) const {
    if (this->isAtEnd()) {
        Utils::throwException<std::out_of_range>(
            std::source_location::current(),
            "cannot move index further @ idx {} | tried {}, max {}: index out of range",
            this->idx, this->idx + 1, 
            this->tokens.size()
        );
    }
    if (!this->checkCurrentTokenType(type)) {
        Utils::throwException<std::runtime_error>(
            std::source_location::current(),
            "strictly expected token \"Token::{}\", found \"{}\"",
            tokenTypeStringRepr.at(type), 
            this->peek().repr()
        );
    }
}

void Parser::assert(std::pair<TokenType, TokenType> types) const {
    if (this->isAtEnd()) {
        Utils::throwException<std::out_of_range>(
            std::source_location::current(),
            "cannot move index further @ idx {} | tried {}, max {}: index out of range",
            this->idx, this->idx + 1, 
            this->tokens.size()
        );
    }
    if (
        !(this->checkCurrentTokenType(types.first) || 
          this->checkCurrentTokenType(types.second))
    ) {
        Utils::throwException<std::runtime_error>(
            std::source_location::current(),
            "expected token \"Token::{}\" or \"Token::{}\", found \"{}\"",
            tokenTypeStringRepr.at(types.first), 
            tokenTypeStringRepr.at(types.second), 
            this->peek().repr()
        );
    }
}

void Parser::expect(TokenType type) {
    if (this->isAtEnd()) {
        Utils::throwException<std::out_of_range>(
            std::source_location::current(),
            "cannot move index further @ idx {} | tried {}, max {}: index out of range",
            this->idx, this->idx + 1, 
            this->tokens.size()
        );
    }
    if (this->checkCurrentTokenType(type)) {
        Utils::throwException<std::runtime_error>(
            std::source_location::current(),
            "expected token with type \"Token::{}\", found \"{}\"",
            tokenTypeStringRepr.at(type), 
            this->peek().repr()
        );
    }
    this->idx++;
}

void Parser::expect(std::pair<TokenType, TokenType> types) {
    if (this->isAtEnd()) {
        Utils::throwException<std::out_of_range>(
            std::source_location::current(),
            "cannot move index further @ idx {} | tried {}, max {}: index out of range",
            this->idx, this->idx + 1, 
            this->tokens.size()
        );
    }
    if (
        !(this->checkCurrentTokenType(types.first) || 
        this->checkCurrentTokenType(types.second))
    ) {
        Utils::throwException<std::runtime_error>(
            std::source_location::current(),
            "expected token with type \"Token::{}\" or \"Token::{}\", found \"{}\"",
            tokenTypeStringRepr.at(types.first), 
            tokenTypeStringRepr.at(types.second),
            this->peek().repr()
        );
    }
    this->idx++;
}

// Block nodes parsing
std::unique_ptr<ast::BlockNode::Heading> Parser::parseHeading() {
    this->assert(TokenType::Hash);

    int depth = this->next().value.size();
    std::vector<std::unique_ptr<ast::InlineNode::InlineNode>> children = this->parseInlineTokens();

    return std::make_unique<ast::BlockNode::Heading>(std::move(children), depth);
}

std::unique_ptr<ast::BlockNode::Paragraph> Parser::parseParagraph() {
    std::vector<std::unique_ptr<ast::InlineNode::InlineNode>> children = this->parseInlineTokens();

    return std::make_unique<ast::BlockNode::Paragraph>(std::move(children));
}

std::unique_ptr<ast::BlockNode::List> Parser::parseList() {
    std::vector<std::unique_ptr<ast::BlockNode::ListItem>> children;

    while (this->checkCurrentTokenType(TokenType::Hyphen)) {
        this->next();
        children.push_back(std::move(this->parseListItem()));
    }
    
    return std::make_unique<ast::BlockNode::List>(std::move(children));
}

std::unique_ptr<ast::BlockNode::ListItem> Parser::parseListItem() {
    std::vector<std::unique_ptr<ast::InlineNode::InlineNode>> children = this->parseInlineTokens();

    return std::make_unique<ast::BlockNode::ListItem>(std::move(children));
}

std::unique_ptr<ast::BlockNode::CodeBlock> Parser::parseCodeBlock() {
    this->expect(TokenType::OpeningCodeSequence);
    std::string lang = "";
    std::vector<std::unique_ptr<ast::InlineNode::InlineNode>> children;

    return std::make_unique<ast::BlockNode::CodeBlock>(std::move(children), lang);
}

// Inline nodes parsing
std::unique_ptr<ast::InlineNode::Bold> Parser::parseBold() {
    this->expect(TokenType::Asterisk);
}

std::unique_ptr<ast::InlineNode::Italic> Parser::parseItalic() {

}

std::unique_ptr<ast::InlineNode::Link> Parser::parseLink() {

}

std::unique_ptr<ast::InlineNode::InlineCode> Parser::parseInlineCode() {

}

std::unique_ptr<ast::InlineNode::Text> Parser::parseText() {

}

std::vector<std::unique_ptr<ast::InlineNode::InlineNode>> Parser::parseInlineTokens() {
    switch (this->peek().type) {
    case TokenType::Asterisk:
        switch (this->peek().value.size()) {
        case 1:
            this->parseItalic();
            break;
        case 2:
            this->parseBold();
        default:
            break;
        }
        break;
    default:
        break;
    }
}

// public
std::unique_ptr<ast::BlockNode::Document> Parser::parseDocument() {

}