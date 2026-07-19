#pragma once

#include "ast/BlockNode/BlockNode.h"
#include "ast/InlineNode/InlineNode.h"
#include "utils/NodeConcatenation.h"
#include "utils/FormatString.h"

struct Heading : public BlockNode {
    int depth = 1; // numeration starts from one
    std::vector<std::unique_ptr<InlineNode>> children;

    std::string toHtml() const override {
        std::string html;

        html.append(getFormattedString("<h{}>", depth));
        html.append(NodeConcatenation::mergePreviousChildrenNodes(children));
        html.append(getFormattedString("</h{}>\n"));

        return html;
    }

    ~Heading() override = default;
};