#pragma once

#include <ast/BlockNode/_BlockNode.h>

namespace ast::BlockNode {
    struct ListItem : public BlockNode {
        std::vector<std::unique_ptr<BlockNode>> children;

        ListItem(std::vector<std::unique_ptr<BlockNode>> children) : children(std::move(children)) {}

        std::string toHtml() const override;

        ~ListItem() override = default;
    };
}
