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

        if (root == nullptr) return 0;

        leftPath = maxPathSumHelper(root->left, maxPathSum);
        rightPath = maxPathSumHelper(root->right, maxPathSum);
        
        localDiameter = leftPath + rightPath + root->val;
        maxChildPath = std::max(leftPath, rightPath);

        maxPathSum = std::max(std::max(localDiameter, maxChildPath), maxPathSum);

        return maxChildPath + root->val;
        // problem: if maxChildPath is the maximum, then the tree will be disconnected...
        // we need a way to keep maxChildPath if it is the maximum
        // idea: instead of keeping track of just the maxDiameter, keep track of the
        // max path sum
        // therefore: you want to always be returning the current max child path + root
    }
};
// @lc code=end

