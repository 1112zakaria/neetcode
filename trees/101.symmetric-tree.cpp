/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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

class Solution {
public:
    /**
     * Approach:
     * - maintain two root pointers A (left) and B (right)
     * - A.left and B.right subtrees must be equal
     * - A.right and B.left subtrees must be equal
     * - base case: roots are NULL
     * - recursive case:
    */
    bool isSymmetric(TreeNode* root) {
        return areRootsMirrored(root->left, root->right);
    }

    bool areRootsMirrored(TreeNode* rootA, TreeNode* rootB) {
        if (rootA == nullptr && rootB == nullptr) {
            return true;
        }
        if (rootA == nullptr || rootB == nullptr || rootA->val != rootB->val) {
            return false;
        }
        return areRootsMirrored(rootA->left, rootB->right) && 
            areRootsMirrored(rootA->right, rootB->left);
    }
};
// @lc code=end

