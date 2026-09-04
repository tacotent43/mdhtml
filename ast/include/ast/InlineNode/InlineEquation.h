#pragma once

#include <ast/InlineNode/_InlineNode.h>

// TODO: implement in .cpp
namespace ast::InlineNode {
    struct InlineEquation : public InlineNode {
        std::string equation;

        InlineEquation(std::string equation) : equation(equation) {}

        std::string toHtml() const override;

        ~InlineEquation() override = default;
    };
}