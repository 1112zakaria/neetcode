/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
     * Approach #1 (recursive, O(n), O(logn)):
     * - traverse recursively while maintaining a stack
     * of the traversal history
     * - base case: node is leaf, check that path sum matches target and
     * add history to output
     * - recursive case: node is non-leaf
    */
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> output;
        vector<int> pathStack;
        helper(root, targetSum, 0, pathStack, output);
        return output;
    }

private:
    void helper(TreeNode *root, int targetSum, int pathSum, vector<int> &pathStack, vector<vector<int>> &output) {
        if (root == nullptr) {
            return;
        }

        // push to pathStack
        int currSum = pathSum + root->val;
        pathStack.push_back(root->val);
        
        // base case: root is leaf
        if (root->left == nullptr && root->right == nullptr) {
            // check sum, if it matches, append pathStack to output
            if (currSum == targetSum) {
                output.push_back(pathStack);
            }
            pathStack.pop_back();
            return;
        }

        // recursive case: root is non-leaf
        helper(root->left, targetSum, currSum, pathStack, output);
        helper(root->right, targetSum, currSum, pathStack, output);

        // pop from pathStack
        pathStack.pop_back();
        return;
    }
};
// @lc code=end

