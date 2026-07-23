#include <ast/BlockNode/Document.h>

namespace ast::BlockNode {
    std::string Document::toHtml() const {
        std::string html;

        html.append("<body>\n");
        html.append(mergePreviousChildrenNodes(this->children));
        html.append("</body>\n");

        return html;
    }
}