#pragma once

#include "ast/BlockNode/BlockNode.h"
#include "ast/BlockNode/include/ListItem.h"
#include "utils/include/NodeConcatenation.h"

namespace ast::BlockNode {
    struct List : public BlockNode {
        std::vector<std::unique_ptr<ListItem>> children;

        std::string toHtml() const override;

        ~List() override = default;
    };
}