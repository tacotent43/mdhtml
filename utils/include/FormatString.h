#pragma once

#include <format>
#include <string>
#include <string_view>

namespace FormatString {
    template<typename... Args>
    inline std::string getFormattedString(std::string_view rt_fmt_str, Args&&... args) {
        // gets format string and replaces "{} " with data of any type.
        return std::vformat(rt_fmt_str, std::make_format_args(args...));
    }
}
