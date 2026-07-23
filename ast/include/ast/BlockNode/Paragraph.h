#pragma once

#include <ast/BlockNode/_BlockNode.h>
#include <ast/InlineNode/_InlineNode.h>

namespace ast::BlockNode {
    struct Paragraph : public BlockNode {
        std::vector<std::unique_ptr<ast::InlineNode::InlineNode>> children;

        std::string toHtml() const override;

        ~Paragraph() override = default;
    };
}