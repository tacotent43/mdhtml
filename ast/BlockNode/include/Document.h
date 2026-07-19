#pragma once

#include "ast/BlockNode/BlockNode.h"
#include "utils/NodeConcatenation.h"

struct Document : public BlockNode {
    std::vector<std::unique_ptr<BlockNode>> children;

    std::string toHtml() const override {
        std::string html;

        html.append("<body>\n");
        html.append(NodeConcatenation::mergePreviousChildrenNodes(this->children));
        html.append("</body>\n");

        return html;
    }

    ~Document() override = default;
};