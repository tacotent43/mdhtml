#pragma once

#include <ast/BlockNode/_BlockNode.h>
#include <ast/InlineNode/_InlineNode.h>
#include <utils/FormatString.h>

namespace ast::BlockNode {
    struct CodeBlock : public BlockNode {
        std::string lang;
        std::vector<std::unique_ptr<ast::InlineNode::InlineNode>> children;

        CodeBlock(std::vector<std::unique_ptr<ast::InlineNode::InlineNode>> children, std::string lang) : lang(std::move(lang)), children(std::move(children)) {}

        std::string toHtml() const override;

        ~CodeBlock() override = default;
    };
}