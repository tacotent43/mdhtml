#pragma once

#include "ast/BlockNode/BlockNode.h"
#include "utils/NodeConcatenation.h"

struct ListItem : public BlockNode {
    std::vector<std::unique_ptr<BlockNode>> children;

    std::string toHtml() const override {
        std::string html;

        html.append("<li>");
        html.append(NodeConcatenation::mergePreviousChildrenNodes(this->children));
        html.append("</li>\n");

        return html;
    }

    ~ListItem() override = default;
};