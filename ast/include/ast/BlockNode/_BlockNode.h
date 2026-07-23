#pragma once

#include <ast/Node.h>

namespace ast::BlockNode {
    struct BlockNode : public Node {
        template <typename T>
        std::string mergePreviousChildrenNodes(const std::vector<std::unique_ptr<T>> &children) const {
            std::string mergedPreviousChildrenNodes;

            for (const std::unique_ptr<T> &child : children) {
                mergedPreviousChildrenNodes.append(child->toHtml());
            }

            return mergedPreviousChildrenNodes;
        }

        ~BlockNode() override = default;
    };
}