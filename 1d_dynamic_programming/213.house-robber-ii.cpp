/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Approach (memoization, O(n)):
     * - constraint: can't rob two adjacent houses
     * - goal: optimize for max money
     * - foreach house k, rob:
     *      - house k-1
     *      - house k-2 + house k
     * - problem: first and last elements are adjacent
     * - solution: run house robber with both in their
     * own subsets and return the max 
    */
    int rob(vector<int>& nums) {
        int robbed1, robbed2;

        if (nums.size() == 1) {
            return nums[0];
        }

        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        robbed1 = helper(nums, 0, nums.size()-2);
        robbed2 = helper(nums, 1, nums.size()-1);
        return max(robbed1, robbed2);
    }

private:
    int helper(vector<int> &nums, int start, int end) {
        int size = end - start + 1;
        vector<int> robbed_values;
        int max_robbed = 0;

        if (size >= 1) {
            max_robbed = nums[start];
            robbed_values.push_back(max_robbed);
        }

        if (size >= 2) {
            max_robbed = max(nums[start], nums[start+1]);
            robbed_values.push_back(max_robbed);
        }

        for (int i=2; i<size; i++) {
            max_robbed = max(robbed_values[i-1], robbed_values[i-2] + nums[start + i]);
            robbed_values.push_back(max_robbed);
        }

        return max_robbed;
    }
};
// @lc code=end

