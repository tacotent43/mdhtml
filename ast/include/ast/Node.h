#pragma once

#include <vector>
#include <memory>
#include <string>

namespace ast {
    struct Node {
        virtual std::string toHtml() const = 0;

        virtual ~Node() = default;
    };
}
