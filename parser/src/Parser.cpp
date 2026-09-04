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

// Block nodes parsing
std::unique_ptr<ast::BlockNode::Heading> Parser::parseHeading() {
    
}

std::unique_ptr<ast::BlockNode::Paragraph> Parser::parseParagraph() {

}

std::unique_ptr<ast::BlockNode::List> Parser::parseList() {

}

std::unique_ptr<ast::BlockNode::ListItem> Parser::parseListItem() {

}

std::unique_ptr<ast::BlockNode::CodeBlock> Parser::parseCodeBlock() {

}

// Inline nodes parsing
std::unique_ptr<ast::InlineNode::Bold> Parser::parseBold() {

}

std::unique_ptr<ast::InlineNode::Italic> Parser::parseItalic() {

}

std::unique_ptr<ast::InlineNode::Link> Parser::parseLink() {

}

std::unique_ptr<ast::InlineNode::InlineCode> Parser::parseInlineCode() {

}

std::unique_ptr<ast::InlineNode::Text> Parser::parseText() {

}

// public
std::unique_ptr<ast::BlockNode::Document> Parser::parseDocument {

}