#include "ast/BlockNode/include/List.h"

namespace ast::BlockNode {
    std::string List::toHtml() const {
        std::string html;

        // TODO: add full support for ul / ol
        html.append("<ul>\n");
        html.append(NodeConcatenation::mergePreviousChildrenNodes(this->children));
        html.append("</ul>\n");

        return html;
    }
}