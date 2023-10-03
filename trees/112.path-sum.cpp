/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 */

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
     * - DFS the tree, subtract the value of the node
     * at each traversal.
     * - if remaining sum is 0 at a leaf, return true
     * - else, return false
     * - return the logical OR of both left and right child
     * results
    */
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        return helper(root, targetSum, targetSum);
    }

private:
    bool helper(TreeNode* root, int targetSum, int currentSum) {
        if (root == nullptr) {
            return false;
        }
        if (currentSum == 0 && !root->left && !root->right) {
            return true;
        }
        if (currentSum < 0) {
            return false;
        }

        currentSum -= root->val;
        return helper(root->left, targetSum, currentSum) || helper(root->right, targetSum, currentSum);
    }
};
// @lc code=end

