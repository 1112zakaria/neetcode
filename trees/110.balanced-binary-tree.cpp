/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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

#if 1
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

#include <cmath>
#include <algorithm>

class Solution {
public:
    /**
     * Approach:
     * - for every subtree:
     *      - check that the difference between the depth of left and right subtrees
     *      is no greater than 1, return max depth + 1, else return -1
     *      - return the max depth + 1
     * - base case: root is null
     * - recursive case:
    */
    bool isBalanced(TreeNode* root) {
        int leftDepth = 0, rightDepth = 0;
        
        return isBalancedHelper(root) > -1; 
    }

private:
    int isBalancedHelper(TreeNode* root) {
        int leftDepth, rightDepth;    

        if (root == nullptr) return 0;

        leftDepth = isBalancedHelper(root->left);
        rightDepth = isBalancedHelper(root->right);

        if (leftDepth == -1 || rightDepth == -1 || std::abs(leftDepth - rightDepth) > 1) {
            return -1;
        }
        return 1 + std::max(leftDepth, rightDepth);
    }
};
// @lc code=end

