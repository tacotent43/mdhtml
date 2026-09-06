#pragma once

#include <vector>
#include <source_location>

#include <ast/BlockNodes.h>
#include <ast/InlineNodes.h>
#include <lexer/Lexer.h>

class Parser {
    std::vector<Token> tokens;
    size_t idx = 0;

    bool isAtEnd() const;
    
    Token peek() const;
    Token next();

    bool check(TokenType type) const;
    void assert(TokenType type) const;
    void expect(TokenType type);

    // Block nodes parsing
    std::unique_ptr<ast::BlockNode::Heading> parseHeading();
    std::unique_ptr<ast::BlockNode::Paragraph> parseParagraph();
    std::unique_ptr<ast::BlockNode::List> parseList();
    std::unique_ptr<ast::BlockNode::ListItem> parseListItem();
    std::unique_ptr<ast::BlockNode::CodeBlock> parseCodeBlock();

    std::vector<std::unique_ptr<ast::BlockNode::BlockNode>> parseBlockTokens();

    // Inline nodes parsing
    std::unique_ptr<ast::InlineNode::Bold> parseBold();
    std::unique_ptr<ast::InlineNode::Italic> parseItalic();
    std::unique_ptr<ast::InlineNode::Link> parseLink();
    std::unique_ptr<ast::InlineNode::InlineCode> parseInlineCode();
    std::unique_ptr<ast::InlineNode::Text> parseText();

    std::vector<std::unique_ptr<ast::InlineNode::InlineNode>> parseInlineTokens()

public:
    std::unique_ptr<ast::BlockNode::Document> parseDocument();
};