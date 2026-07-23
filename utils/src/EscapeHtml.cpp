#include <utils/EscapeHtml.h>

namespace Utils {
    std::string EscapeHtml(const std::string_view token) {
        std::string result;

        for (char c : token) {
            switch (c) {
                case '&':
                    result += "&amp;";
                    break;
                case '<':
                    result += "&lt;";
                    break;
                case '>':
                    result += "&gt;";
                    break;
                case '"':
                    result += "&quot;";
                    break;
                case '\'':
                    result += "&#39;";
                    break;
                default:
                    result += c;
            }
        }

        return result;
    }
}