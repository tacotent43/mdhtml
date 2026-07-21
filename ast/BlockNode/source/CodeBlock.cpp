#include "ast/BlockNode/include/CodeBlock.h"

namespace ast::BlockNode {
    std::string CodeBlock::toHtml() const {
        std::string html;

        html.append("<pre data-lang=\"cpp\"><code>");
        html.append(NodeConcatenation::mergePreviousChildrenNodes(this->children));
        html.append("</code></pre>\n");

        return html;
    }
}