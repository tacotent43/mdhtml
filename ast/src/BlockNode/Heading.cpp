#include <ast/BlockNode/Heading.h>

namespace ast::BlockNode {
    std::string Heading::toHtml() const {
        std::string html;

        html.append(Utils::getFormattedString("<h{}>", this->depth));
        html.append(mergePreviousChildrenNodes(this->children));
        html.append(Utils::getFormattedString("</h{}>\n", this->depth));

        return html;
    }
}