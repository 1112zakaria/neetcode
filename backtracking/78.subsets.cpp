/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

#include <vector>
#include <set>
#include <iterator>
using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Approach: (O(n*2^n)), recursion:
     * - iterate each element recursively
     * - foreach element, you will have a left and a right set,
     *  - left set appends the current value
     *  - right set does not add the current value
     * - recursively add the next value to both left and right sets
     * - when there are no more values that can be added, append the
     * current set of the recursion stack to the output list
     * 
    */
    vector<vector<int>> subsets(vector<int>& nums) {
        set<int> values;
        vector<vector<int>> output;
        vector<int> init_subset;
        
        // Store nums in a set for no duplicates
        for (int i=0; i<nums.size(); i++) {
            values.insert(nums[i]);
        }

        helper(nums, 0, init_subset, output);
        return output;
    }

private:
    void helper(vector<int> &nums, int idx, vector<int> &subset, vector<vector<int>> &output) {
        vector<int> left, right;

        // base case: idx >= nums.size()
        if (idx >= nums.size()) {
            output.push_back(subset);
            return;
        }

        left = subset;
        left.push_back(nums[idx]);
        right = subset;

        helper(nums, idx+1, left, output);
        helper(nums, idx+1, right, output);
        return;
    }
};
// @lc code=end

