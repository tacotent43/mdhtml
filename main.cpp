#include <format>
#include <iostream>
#include <string>
#include <string_view>

template<typename... Args>
std::string dyna_print(std::string_view rt_fmt_str, Args&&... args) {
    return std::vformat(rt_fmt_str, std::make_format_args(args...));
}

int main() {
    std::string fmt;

    fmt = "<h{}>";
    std::cout << dyna_print(fmt, 2);

    return 0;
}