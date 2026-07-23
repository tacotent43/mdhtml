#include <ast/InlineNode/Italic.h>

namespace ast::InlineNode {
    std::string Italic::toHtml() const {
        std::string html;

        html.append("<i>\n");
        html.append(mergePreviousChildrenNodes(this->children));
        html.append("</i>\n");

        return html;
    }
}