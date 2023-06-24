/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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

#include <cinttypes>
#include <algorithm>

class Solution {
public:
    /**
     * Approach:
     * - recursively iterate over each subtree, while updating the current
     * largest node value in the subtree
     * - base case: root is null
     * - recursive case: root is not null
     * - for each subtree:
     *      - compare the largest path node with the root and update accordingly
     *      - get the number of good nodes in the child nodes
     *      - return the number of good nodes in the child nodes + 1 if root is good node
    */
    int goodNodes(TreeNode* root) {
        return goodNodesHelper(root, root->val);
    }

private:

    int goodNodesHelper(TreeNode* root, int maxPathNode) {
        int isNodeGood = 1;

        if (root == nullptr) return 0;

        maxPathNode = std::max(root->val, maxPathNode);
        if (root->val < maxPathNode) isNodeGood = 0;
        return goodNodesHelper(root->left, maxPathNode) + 
            goodNodesHelper(root->right, maxPathNode) + isNodeGood;
    }
};
// @lc code=end

