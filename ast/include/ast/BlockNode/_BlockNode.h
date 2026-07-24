#pragma once

#include <ast/Node.h>

namespace ast::BlockNode {
    struct BlockNode : public Node {
        ~BlockNode() override = default;
    };
}