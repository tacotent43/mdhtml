#pragma once

#include <ast/InlineNode/_InlineNode.h>

namespace ast::InlineNode {
    struct Italic : public InlineNode {
        std::vector<std::unique_ptr<InlineNode>> children;

        Italic(std::vector<std::unique_ptr<InlineNode>> children) : children(std::move(children)) {}

        std::string toHtml() const override;

        ~Italic() override = default;
    };
}