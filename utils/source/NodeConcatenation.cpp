#include "utils/include/NodeConcatenation.h"

namespace NodeConcatenation {
    // TODO: templates instead of overload?
    std::string mergePreviousChildrenNodes(const std::vector<std::unique_ptr<ast::BlockNode::BlockNode>> &children) {
        std::string mergedPreviousChildrenNodes;
        
        for (const std::unique_ptr<ast::BlockNode::BlockNode> &child : children) {
            if (!mergedPreviousChildrenNodes.empty()) {
                mergedPreviousChildrenNodes += '\n';
            }
            mergedPreviousChildrenNodes += child->toHtml();
        }

        return mergedPreviousChildrenNodes;
    }
    
    // TODO: something like delimiter?
    std::string mergePreviousChildrenNodes(const std::vector<std::unique_ptr<ast::InlineNode::InlineNode>> &children) {
        std::string mergedPreviousChildrenNodes;

        for (const std::unique_ptr<ast::InlineNode::InlineNode> &child : children) {
            mergedPreviousChildrenNodes += child->toHtml();
        }

        return mergedPreviousChildrenNodes;
    }

    std::string mergePreviousChildrenNodes(const std::vector<std::unique_ptr<ast::BlockNode::ListItem>> &children) {
        std::string mergedPreviousChildrenNodes;

        for (const std::unique_ptr<ast::BlockNode::ListItem> &child : children) {
            mergedPreviousChildrenNodes += child->toHtml();
        }

        return mergedPreviousChildrenNodes;
    }
}