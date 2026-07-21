#pragma once

#include <vector>
#include <string>
#include <memory>

#include "ast/BlockNode/BlockNode.h"
#include "ast/InlineNode/InlineNode.h"
#include "ast/BlockNode/include/ListItem.h"

namespace NodeConcatenation {
    // TODO: templates instead of overload?
    std::string mergePreviousChildrenNodes(const std::vector<std::unique_ptr<ast::BlockNode::BlockNode>> &children);
    
    // TODO: something like delimiter?
    std::string mergePreviousChildrenNodes(const std::vector<std::unique_ptr<ast::InlineNode::InlineNode>> &children);

    std::string mergePreviousChildrenNodes(const std::vector<std::unique_ptr<ast::BlockNode::ListItem>> &children);
}