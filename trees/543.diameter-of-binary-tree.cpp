/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
     * - at the root, return the sum of the left + right subtree lengths
     * - for every subtree, return 1 + the max length of the right & left subtrees
     * Approach #2:
     * - idea: a node can either be an edge or root node in the diameter
     *      - therefore, store the length of the longest edge AND length of the longest
     *      known diameter
     * - for every subtree, compare:
     *      - length of the left subtree
     *      - length of the right subtree
     *      - length of the local diameter = length of left sub + 
    */
    int diameterOfBinaryTree(TreeNode* root) {
        int longestLocalDiameter = 0;
        int maxLeftLength, maxRightLength;

        if (root == nullptr) return 0;

        maxLeftLength = getMaxLengthHelper(root->left, longestLocalDiameter);
        maxRightLength = getMaxLengthHelper(root->right, longestLocalDiameter);
        return std::max(maxLeftLength + maxRightLength, longestLocalDiameter);
    }

    int getMaxLengthHelper(TreeNode* root, int &longestDiameter) {
        int localDiameter;
        int leftLength, rightLength;

        if (root == nullptr) return 0;
        leftLength = getMaxLengthHelper(root->left, longestDiameter);
        rightLength = getMaxLengthHelper(root->right, longestDiameter);
        localDiameter = leftLength + rightLength;

        longestDiameter = std::max(localDiameter, longestDiameter);
        return 1 + std::max(leftLength, rightLength);
    }
};
// @lc code=end

