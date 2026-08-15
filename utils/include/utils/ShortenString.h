#pragma once

#include <string>
#include <utils/FormatString.h>

namespace Utils {
    std::string shortenString(const std::string_view &str, size_t shortenTo);
}