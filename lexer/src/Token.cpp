#include <lexer/Token.h>

std::string Token::repr(int indent) const {
    std::string shortened;
    std::string indentStr;

    shortened = (
        this->value.size() > 42 ? 
            Utils::shortenString(value, static_cast<size_t>(this->value.size() / 4))
                : value);

    indentStr = std::string(indent, '\t');

    return Utils::getFormattedString(
        "{}TOKEN @ {}l {}s \{\n{}\tType: {}\n{}\tValue: {}\n{}\}",

        indentStr, this->position.line, this->position.symbol, 
        indentStr, tokenTypeStringRepr.at(this->type)),
        indentStr, shortened,
        indentStr
    );
}