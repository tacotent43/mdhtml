#include <ast/InlineNode/InlineCode.h>

namespace ast::InlineNode {
    std::string InlineCode::toHtml() const {
        std::string html;

        html.append("<code>\n");
        html.append(mergePreviousChildrenNodes(this->children));
        html.append("</code>\n");

        return html;
    }
}