#pragma once

#include <vector>
#include <memory>
#include <string>

struct Node {
    virtual std::string toHtml() const;

    virtual ~Node() = default;
};