/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

#include <vector>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Approach:
     * - since the array is sorted, the goal is to narrow down the set
     * of integers that need to be searched
     * - define start, end, and median
     * - cases:
     *      - target == median, return median index
     *      - target > median, search(median+1, end)
     *      - target < median, search(start, median-1)
     * - base case: start > end or end < start
     * - recursive case:
    */
    int search(vector<int>& nums, int target) {
        #if 0
        return searchHelperRecursive(nums, target, 0, nums.size()-1);
        #else
        return searchHelperIterative(nums, target);
        #endif
    }

private:
    int searchHelperRecursive(vector<int> &nums, int target, int s_idx, int e_idx) {
        int m_idx, median;

        if (s_idx > e_idx || e_idx < s_idx) return -1;
        
        m_idx = ceil( (e_idx - s_idx) / 2 ) + s_idx;
        median = nums[m_idx];

        if (target == median) return m_idx;
        if (target > median) return searchHelperRecursive(nums, target, m_idx+1, e_idx);
        return searchHelperRecursive(nums, target, s_idx, m_idx-1);
    }

    int searchHelperIterative(vector<int> &nums, int target) {
        int m_idx, median, s_idx, e_idx;
        int target_idx = -1;

        s_idx = 0;
        e_idx = nums.size() - 1;

        while (s_idx <= e_idx && e_idx >= s_idx && target_idx == -1) {
            m_idx = ceil ( (e_idx - s_idx) / 2 ) + s_idx;
            median = nums[m_idx];
            
            if (target == median) {
                target_idx = m_idx;
            }
            else if (target > median) {
                s_idx = m_idx + 1;
            }
            else if (target < median) {
                e_idx = m_idx - 1;
            }
        }
        return target_idx;

    }
};
// @lc code=end

