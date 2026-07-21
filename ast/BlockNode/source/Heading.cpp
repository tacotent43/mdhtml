#include "ast/BlockNode/include/Heading.h"

namespace ast::BlockNode {
    std::string Heading::toHtml() const {
        std::string html;

        html.append(FormatString::getFormattedString("<h{}>", depth));
        html.append(NodeConcatenation::mergePreviousChildrenNodes(this->children));
        html.append(FormatString::getFormattedString("</h{}>\n"));

        return html;
    }
}