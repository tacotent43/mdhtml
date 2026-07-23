#pragma once

#include "ast/BlockNode/BlockNode.h"
#include "ast/InlineNode/InlineNode.h"
#include "utils/include/NodeConcatenation.h"
#include "utils/include/FormatString.h"

namespace ast::BlockNode {
    struct Heading : public BlockNode {
        int depth = 1; // numeration starts from one
        std::vector<std::unique_ptr<ast::InlineNode::InlineNode>> children;

        std::string Heading::toHtml() const override;

        ~Heading() override = default;
    };
}