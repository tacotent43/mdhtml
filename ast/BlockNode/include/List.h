#pragma once

#include "ast/BlockNode/BlockNode.h"
#include "ast/BlockNode/ListItem.h"
#include "utils/NodeConcatenation.h"

struct List : public BlockNode {
    std::vector<std::unique_ptr<ListItem>> children;

    std::string toHtml() const override {
        std::string html;

        // TODO: add full support for ul / ol
        html.append("<ul>\n");
        html.append(NodeConcatenation::mergePreviousChildrenNodes(this->children));
        html.append("</ul>\n");

        return html;
    }

    ~List() override = default;
};