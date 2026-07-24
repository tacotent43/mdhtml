#pragma once

#include <vector>
#include <memory>
#include <string>

namespace ast {
    struct Node {
        template <typename T>
        std::string mergePreviousChildrenNodes(const std::vector<std::unique_ptr<T>> &children) const {
            std::string mergedPreviousChildrenNodes;

            for (const std::unique_ptr<T> &child : children) {
                mergedPreviousChildrenNodes.append(child->toHtml());
            }

            return mergedPreviousChildrenNodes;
        }

        virtual std::string toHtml() const = 0;

        virtual ~Node() = default;
    };
}
