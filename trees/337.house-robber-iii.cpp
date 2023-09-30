/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 */

#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
class Solution {
public:
    /**
     * Approach (DFS, O(n)):
     * - summary: foreach subtree, return the max of (left + right)
     * and root values
    */
    int rob(TreeNode* root) {
        return helper(root);
    }

private:
    int helper(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int child_val = helper(root->left) + helper(root->right);
        return std::max(child_val, root->val);
    }
};
// @lc code=end

