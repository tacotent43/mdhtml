#pragma once

#include "ast/BlockNode/BlockNode.h"
#include "ast/InlineNode/InlineNode.h"
#include "utils/include/NodeConcatenation.h"

namespace ast::BlockNode {
    struct Paragraph : public BlockNode {
        std::vector<std::unique_ptr<ast::InlineNode::InlineNode>> children;

        std::string toHtml() const override;

        ~Paragraph() override = default;
    };
}