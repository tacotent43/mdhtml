#pragma once

#include <string>
#include <utils/FormatString.h>

namespace Utils {
    std::string shortenString(const std::string_view &str, size_t shortenTo) {
        std::string beginning, ending;
        
        for (size_t i = 0; i < shortenTo; ++i) {
            beginning.push_back(str[i]);
        }

        for (size_t i = str.size() - shortenTo - 1; i < str.size(); ++i) {
            ending.push_back(str[i]);
        }

        return getFormattedString("{}... ...{}", beginning, ending);
    }
}