#pragma once

#include <ast/BlockNode/_BlockNode.h>
#include <ast/InlineNode/_InlineNode.h>
#include <utils/FormatString.h>

namespace ast::BlockNode {
    struct Heading : public BlockNode {
        int depth = 1; // numeration starts from one
        std::vector<std::unique_ptr<ast::InlineNode::InlineNode>> children;

        Heading(std::vector<std::unique_ptr<ast::InlineNode::InlineNode>> children, int depth) : depth(depth), children(std::move(children)) {}

        std::string toHtml() const override;

        ~Heading() override = default;
    };
}