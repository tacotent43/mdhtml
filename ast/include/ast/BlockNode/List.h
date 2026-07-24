#pragma once

#include <ast/BlockNode/_BlockNode.h>
#include <ast/BlockNode/ListItem.h>

namespace ast::BlockNode {
    struct List : public BlockNode {
        std::vector<std::unique_ptr<ListItem>> children;

        List(std::vector<std::unique_ptr<ListItem>> children) : children(std::move(children)) {}

        std::string toHtml() const override;

        ~List() override = default;
    };
}