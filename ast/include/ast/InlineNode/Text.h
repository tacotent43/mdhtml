#pragma once

#include <ast/InlineNode/_InlineNode.h>
#include <utils/EscapeHtml.h>

namespace ast::InlineNode {
    struct Text : public InlineNode {
        std::string text;

        Text(std::string text) : text(std::move(text)) {}

        std::string toHtml() const override;

        ~Text() override = default;
    };
}