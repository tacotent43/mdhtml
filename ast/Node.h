#pragma once

#include <vector>
#include <memory>
#include <string>

struct Node {
    virtual std::string toHtml();

    virtual ~Node() = default;
};