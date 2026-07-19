#pragma once

#include "ast/BlockNode/BlockNode.h"
#include "ast/InlineNode/InlineNode.h"
#include "utils/NodeConcatenation.h"

struct CodeBlock : public BlockNode {
    std::vector<std::unique_ptr<InlineNode>> children;

    std::string toHtml() const override {
        std::string html;

        html.append("<pre data-lang=\"cpp\"><code>");
        html.append(NodeConcatenation::mergePreviousChildrenNodes(this->children));
        html.append("</code></pre>\n");

        return html;
    }

    ~CodeBlock() override = default;
};