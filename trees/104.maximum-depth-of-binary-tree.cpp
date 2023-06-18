/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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

#include <algorithm>

#if 1
 //Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif


class Solution {
public:
    /**
     * Approach:
     * - recursively traverse the left and right nodes and get the
     * largest of the returned depth of the two nodes + 1
     * - if root is null, return 0
    */
    int maxDepth(TreeNode* root) {
        int r_depth, l_depth;
        if (root == nullptr) return 0;
        l_depth = maxDepth(root->left);
        r_depth = maxDepth(root->right);
        return std::max(l_depth, r_depth) + 1;
    }
};
// @lc code=end

