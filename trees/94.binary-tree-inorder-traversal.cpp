/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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

#include <vector>

#if 1
using namespace std;

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
     * - Inorder: left, root, then right
     * - 
    */
    vector<int> inorderTraversal(TreeNode* root) {
        //vector<int> traversed = vector<int>();
        vector<int> traversed;
        inorderTraversalHelper(root, traversed);
        return traversed;
    }

    void inorderTraversalHelper(TreeNode* root, vector<int> &traversed) {
        if (root == NULL) return;
        inorderTraversalHelper(root->left, traversed);
        traversed.push_back(root->val);
        inorderTraversalHelper(root->right, traversed);
    }
};
// @lc code=end

