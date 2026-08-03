#pragma once

#include <format>
#include <string>
#include <string_view>
#include <source_location>

namespace Utils {
    template<class Exception, class... Args>
    [[noreturn]] void throwException(
        std::source_location location,
        std::string_view fmt,
        Args&&... args
    ) {
        const char* function = location.function_name();
        std::string message = std::vformat(
            fmt,
            std::make_format_args(args...)
        );

        throw Exception(
            std::vformat(
                "[{}] {}\n",
                std::make_format_args(function, message)
            )
        );
    }
}