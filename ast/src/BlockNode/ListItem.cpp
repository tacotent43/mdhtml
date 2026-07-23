#include <ast/BlockNode/ListItem.h>

namespace ast::BlockNode {
    std::string ListItem::toHtml() const {
        std::string html;

        html.append("<li>");
        html.append(mergePreviousChildrenNodes(this->children));
        html.append("</li>\n");

        return html;
    }
}