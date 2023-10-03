/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

#include <vector>

using namespace std;

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
     * Approach (recursive, O(n)):
     * - traverse BST
     * - maintain depth key i and list of lists
     * - 
    */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output;
        helper(root, 0, output);
        return output;
    }

private:
    void helper(TreeNode* root, int depth, vector<vector<int>> &output) {
        if (root == nullptr) {
            return;
        }
        
        if (depth >= output.size()) {
            // index does not exist, create
            output.push_back(vector<int>());
        }
        output[depth].push_back(root->val);
        helper(root->left, depth+1, output);
        helper(root->right, depth+1, output);
        return;
    }
};
// @lc code=end

