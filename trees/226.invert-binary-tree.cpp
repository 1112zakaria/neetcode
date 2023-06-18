/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
// Definition for a binary tree node.
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
     * For each node, swap the position of the two children
     * Traverse recursively
    */
    TreeNode* invertTree(TreeNode* root) {
        TreeNode *l_ptr, *r_ptr;
        // base case: root is null
        if (root == nullptr) return nullptr;
        // recursive case: root is not null
        l_ptr = root->left;
        r_ptr = root->right;
        // swap the node ptrs
        root->left = r_ptr;
        root->right = l_ptr;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
// @lc code=end

