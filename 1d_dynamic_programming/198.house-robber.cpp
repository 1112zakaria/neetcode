/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

#include <vector>
//#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Approach (memoization, O(n)):
     * - constraint: can't rob adjacent houses
     * - goal: optimize for max amount of money
     * - calculate the max amount of money that can be robbed
     * looking only at the subset of currently traversed houses
     * - maintain list of max money that can be robbed from houses
     * 1 to k
     * - foreach house k in range(3,n), rob the max of either:
     *      - house k-1
     *      - house k-2 + house k
    */
    int rob(vector<int>& nums) {
        vector<int> robbed_values;
        int max_robbed = 0;

        if (nums.size() >= 1) {
            max_robbed = nums[0];
            robbed_values.push_back(max_robbed);
        }

        if (nums.size() >= 2) {
            max_robbed = max(nums[0], nums[1]);
            robbed_values.push_back(max_robbed);
        }

        for (int i=2; i<nums.size(); i++) {
            max_robbed = max(robbed_values[i-1], robbed_values[i-2] + nums[i]);
            robbed_values.push_back(max_robbed);
        }

        return max_robbed;
    }
};
// @lc code=end

