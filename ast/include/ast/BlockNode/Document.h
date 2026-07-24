#pragma once

#include <ast/BlockNode/_BlockNode.h>

namespace ast::BlockNode {
    struct Document : public BlockNode {
        std::vector<std::unique_ptr<BlockNode>> children;

        Document(std::vector<std::unique_ptr<BlockNode>> children) : children(std::move(children)) {}

        std::string toHtml() const override;

        ~Document() override = default;
    };
}