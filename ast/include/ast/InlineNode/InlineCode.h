#pragma once

#include <ast/InlineNode/_InlineNode.h>

namespace ast::InlineNode {
    struct InlineCode : public InlineNode {
        std::vector<std::unique_ptr<InlineNode>> children;

        InlineCode(std::vector<std::unique_ptr<InlineNode>> children) : children(std::move(children)) {}

        std::string toHtml() const override;

        ~InlineCode() override = default;
    };
}