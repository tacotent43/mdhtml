#include <ast/InlineNode/Text.h>

namespace ast::InlineNode {
    std::string Text::toHtml() const {
        return Utils::EscapeHtml(this->text);
    }
}