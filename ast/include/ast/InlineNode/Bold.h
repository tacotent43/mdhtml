#pragma once

#include <ast/InlineNode/_InlineNode.h>

namespace ast::InlineNode {
    struct Bold : public InlineNode {
        std::vector<std::unique_ptr<InlineNode>> children;

        Bold(std::vector<std::unique_ptr<InlineNode>> children) : children(std::move(children)) {}

        std::string toHtml() const override;

        ~Bold() override = default;
    };
}