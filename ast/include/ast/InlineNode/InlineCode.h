#pragma once

#include <ast/InlineNode/_InlineNode.h>

namespace ast::InlineNode {
    struct InlineCode : public InlineNode {
        std::vector<std::unique_ptr<InlineNode>> children;

        std::string toHtml() const override;

        ~InlineCode() override = default;
    };
}