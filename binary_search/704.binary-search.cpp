/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Approach:
     * - get the middle value, if target<=mid split list from 0-mid,
     * else split list mid+1-n, until size is 1
     * Approach#2:
     * - Base case: if size of window is 1
     * - Recursive case:
    */
    int search(vector<int>& nums, int target) {
        return searchHelperRecursive(nums, target, 0, nums.size()-1);
    }

    int searchHelperRecursive(vector<int> &nums, int target, int start_idx, int end_idx) {
        int mid_idx = (int) (end_idx - start_idx)/2 + start_idx;
        int middle = nums[mid_idx];

        if (middle == target) return mid_idx;
        if (end_idx - start_idx == 0 && nums[end_idx-start_idx] == target) return start_idx;
        if (target <= middle) {
            // split lower
            return searchHelperRecursive(nums, target, 0, mid_idx-1);
        }
        // split upper
        return searchHelperRecursive(nums, target, mid_idx+1, end_idx);
        
    }

    int searchHelperRecursiveB(){}
};
// @lc code=end

