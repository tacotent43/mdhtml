#include <ast/InlineNode/Link.h>

namespace ast::InlineNode {
    std::string Link::toHtml() const {
        std::string html;

        html.append(Utils::getFormattedString("<a href=\"{}\">", this->link));
        html.append(mergePreviousChildrenNodes(this->children));
        html.append("</a>\n");

        return html;
    }
}