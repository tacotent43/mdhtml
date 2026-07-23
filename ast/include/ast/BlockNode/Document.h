#pragma once

#include "ast/BlockNode/BlockNode.h"
#include "utils/include/NodeConcatenation.h"

namespace ast::BlockNode {
    struct Document : public BlockNode {
        std::vector<std::unique_ptr<BlockNode>> children;

        std::string toHtml() const override;

        ~Document() override = default;
    };
}