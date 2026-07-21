#include "ast/BlockNode/include/ListItem.h"

namespace ast::BlockNode {
    std::string ListItem::toHtml() const {
        std::string html;

        html.append("<li>");
        html.append(NodeConcatenation::mergePreviousChildrenNodes(this->children));
        html.append("</li>\n");

        return html;
    }
}