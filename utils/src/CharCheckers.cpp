#include <utils/CharCheckers.h>

namespace Utils {
    bool isSpaceChar(const char ch) {
        switch (ch) {
            case ' ':
                return true;
            case '\t':
                return true;

            default:
                return false;
        }
    }
}