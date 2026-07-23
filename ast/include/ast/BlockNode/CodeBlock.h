#pragma once

#include "ast/BlockNode/BlockNode.h"
#include "ast/InlineNode/InlineNode.h"
#include "utils/include/NodeConcatenation.h"

namespace ast::BlockNode {
    struct CodeBlock : public BlockNode {
        std::vector<std::unique_ptr<ast::InlineNode::InlineNode>> children;

        std::string toHtml() const override;

        ~CodeBlock() override = default;
    };
}