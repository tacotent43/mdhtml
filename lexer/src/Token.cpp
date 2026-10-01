#include <lexer/Token.h>

std::string Token::repr() const {
    return Utils::getFormattedString(
        "Token::{} @ {}l {}s",
        tokenTypeStringRepr.at(this->type),
        this->position.line + 1, this->position.symbol + 1
    );
}

std::string Token::fullRepr() const {
    std::string shortened;

    shortened = (
        this->value.size() > 42 ? 
            Utils::shortenString(value, static_cast<size_t>(this->value.size() / 4))
                : value);

    return Utils::getFormattedString(
        "TOKEN @ {}l {}s [\n\tType: {}\n\tValue: {}\n{}]",
        this->position.line + 1, this->position.symbol + 1, 
        tokenTypeStringRepr.at(this->type),
        shortened    
    );
}