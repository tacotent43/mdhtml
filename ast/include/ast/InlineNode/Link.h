#pragma once

#include <ast/InlineNode/_InlineNode.h>
#include <utils/FormatString.h>

namespace ast::InlineNode {
    struct Link : public InlineNode {
        std::string link;
        std::vector<std::unique_ptr<InlineNode>> children;

        std::string toHtml() const override;

        ~Link() override = default;
    };
}