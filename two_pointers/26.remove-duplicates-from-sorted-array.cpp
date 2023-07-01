/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Approach #1 (naive, O(n^2))
     * 
     * Approach #2 (O(n), O(n) -> O(1)):
     * - iterate over each element & mark the ones that are
     * duplicates in a separate array (is the array needed...
     * is marking needed...)
     * - when a number with a duplicate is detected, increment
     * the number of positions to the left that future numbers
     * will need to be shifted and skip over it
     * - when a non-duplicate number is detected, shift by the
     * current number of shifts & set the lastNum
    */
    int removeDuplicates(vector<int>& nums) {
        int numShifts = 0;
        int curr = 1;
        int lastNum = nums[0];

        while (curr < nums.size()) {
            if (nums[curr] == lastNum) {
                numShifts++;
            } else {
                nums[curr - numShifts] = nums[curr];
                lastNum = nums[curr];
            }
            curr++;
        }
        return nums.size() - numShifts;
    }
};
// @lc code=end

