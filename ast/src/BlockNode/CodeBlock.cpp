#include <ast/BlockNode/CodeBlock.h>

namespace ast::BlockNode {
    std::string CodeBlock::toHtml() const {
        std::string html;

        html.append(Utils::getFormattedString("<pre data-lang=\"{}\"><code>", this->lang));
        html.append(mergePreviousChildrenNodes(this->children));
        html.append("</code></pre>\n");

        return html;
    }
}