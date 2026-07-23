#include "ast/BlockNode/include/Document.h"

namespace ast::BlockNode {
    std::string Document::toHtml() const {
        std::string html;

        html.append("<body>\n");
        html.append(NodeConcatenation::mergePreviousChildrenNodes(this->children));
        html.append("</body>\n");

        return html;
    }
}