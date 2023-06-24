/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#if 0
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

#include <algorithm>

class Solution {
public:
    /**
     * Approach:
     * - background: at a root, you can consider the right subtree,
     * the left subtree, or the local diameter (see LC-543) to be the
     * maximum path sum
     * - for each subtree:
     *      - get max path sum of left subtree
     *      - get max path sum of right subtree
     *      - get max path sum of local diameter = left + right + root
     * - update the max diameter
     * - get maxChildPath = max(left, right)
     * - return max(maxChildPath, maxChildPath + root)
     * - base case: root is null
     * - recursive case:
    */
    int maxPathSum(TreeNode* root) {
        int maxPathSum = root->val;
        int maxRootPath;
        
        if (root->left == nullptr && root->right == nullptr) return root->val;

        maxRootPath = maxPathSumHelper(root, maxPathSum);
        return std::max(maxRootPath, maxPathSum);
    }

private:
    /**
     * Calculates the leftPath, rightPath, localDiameter.
     * localDiameter = leftPath + rightPath + root->val
     * maxChildPath = max(leftPath+rightPath)
     * Writes the max discovered path sum to maxPathSum.
     * Returns maxChildPath + root->val
     * @param root
     * @param maxPathSum
    */
    int maxPathSumHelper(TreeNode* root, int &maxPathSum) {
        int leftPath, rightPath, localDiameter, maxChildPath;

        leftPath = 0;
        rightPath = 0;
        localDiameter = 0;
        maxChildPath = root->val;
        //if (root == nullptr) return 0;
        
        if (root->left != nullptr)
            leftPath = maxPathSumHelper(root->left, maxPathSum);
            localDiameter += leftPath;
            maxPathSum = std::max(leftPath, maxPathSum);
            maxChildPath = std::max(leftPath + root->val, maxChildPath);
        if (root->right != nullptr)
            rightPath = maxPathSumHelper(root->right, maxPathSum);
            localDiameter += rightPath;
            maxPathSum = std::max(rightPath, maxPathSum);
            maxChildPath = std::max(rightPath + root->val, maxChildPath);
        
        localDiameter += root->val;
        maxPathSum = std::max(localDiameter, maxPathSum);

        //maxChildPath = std::max(leftPath, rightPath);
        return maxChildPath;
        // problem: if maxChildPath is the maximum, then the tree will be disconnected...
        // we need a way to keep maxChildPath if it is the maximum
        // idea: instead of keeping track of just the maxDiameter, keep track of the
        // max path sum
        // therefore: you want to always be returning the current max child path + root
        // problem: null children are interfering with the calculations by returning 0
        // solution: don't iterate over null children? issue, localDiameter depends on children
        // q: can there be a localDiameter if one of the children are null? yes
        // problem: maxChildPath should not be included in maxPathSum calculations if one of
        // the nodes, solution: use right and left paths conditionally
        // problem: algorithm does not detect single child node as max path sum, solution: 
    }
};
// @lc code=end

