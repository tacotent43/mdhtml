#include "utils/NodeConcatenation.h"

namespace NodeConcatenation {
    // TODO: templates instead of overload?
    std::string mergePreviousChildrenNodes(const std::vector<std::unique_ptr<BlockNode>> &children) {
        std::string mergedPreviousChildrenNodes;
        
        for (const std::unique_ptr<BlockNode> &child : children) {
            if (!mergedPreviousChildrenNodes.empty()) {
                mergedPreviousChildrenNodes += '\n';
            }
            mergedPreviousChildrenNodes += child->toHtml();
        }

        return mergedPreviousChildrenNodes;
    }
    
    // TODO: something like delimiter?
    std::string mergePreviousChildrenNodes(const std::vector<std::unique_ptr<InlineNode>> &children) {
        std::string mergedPreviousChildrenNodes;

        for (const std::unique_ptr<InlineNode> &child : children) {
            mergedPreviousChildrenNodes += child->toHtml();
        }

        return mergedPreviousChildrenNodes;
    }
}