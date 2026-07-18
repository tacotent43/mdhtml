#pragma once

#include "ast/BlockNode/BlockNode.h"
#include "ast/InlineNode/InlineNode.h"
#include "utils/NodeConcatenation.h"

struct Paragraph : public BlockNode {
    std::vector<std::unique_ptr<InlineNode>> children;

    std::string toHtml() {

    }

    ~Paragraph() override = default;
};