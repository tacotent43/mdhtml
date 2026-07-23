#include <ast/InlineNode/Bold.h>

namespace ast::InlineNode {
    std::string Bold::toHtml() const {
        std::string html;

        html.append("<b>\n");
        html.append(mergePreviousChildrenNodes(this->children));
        html.append("</b>\n");

        return html;
    }
}