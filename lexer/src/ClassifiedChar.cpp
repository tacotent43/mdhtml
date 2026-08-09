#include <lexer/ClassifiedChar.h>

sck ClassifiedChar::classify() {
    if (!specialCharToKind.contains(this->c)) {
        return sck::Text;
    }
    return specialCharToKind.at(this->c);
}