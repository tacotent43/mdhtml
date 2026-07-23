#include <ast/BlockNode/Paragraph.h>

namespace ast::BlockNode {
    std::string Paragraph::toHtml() const {
        std::string html;
        
        html.append("<p>\n");
        html.append(mergePreviousChildrenNodes(this->children));
        html.append("</p>\n");

        return html;
    }
}