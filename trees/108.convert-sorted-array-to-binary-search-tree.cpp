/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
#include <vector>

using namespace std;

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

#include <cmath>

class Solution {
public:
    /**
     * Approach:
     * - base case: start == end
     * - let the median be the root
     * - for every subtree:
     *      - get the median, set as the root
     *      - get the left subset and pass to the left subtree
     *      - get the right subset and pass to the right subtree
     * - return root
    */
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }

    TreeNode* helper(vector<int> &nums, int start, int end) {
        TreeNode* root;
        int median_idx, median;
        int l_start, l_end, r_start, r_end;

        median_idx = ceil((end - start) / 2) + start;
        median = nums[median_idx];
        root = new TreeNode(median);

        if (start == end) {
            return root;
        }

        l_start = start;
        l_end = median_idx - 1;
        r_start = median_idx + 1;
        r_end = end;

        if (l_end >= start) {
            root->left = helper(nums, l_start, l_end);
        }
        if (r_start <= end) {
            root->right = helper(nums, r_start, r_end);
        }
        return root;
    }
};
// @lc code=end

