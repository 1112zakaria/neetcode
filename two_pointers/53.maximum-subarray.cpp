/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        /**
         * Approach:
         * - maintain maxSum, leftPtr, rightPtr
         * - update subarray with the goal of maximizing the localSum, by iterating
         * the left and right pointers until they ~~reach the end of the array~~
         * cross each other
         *  - shift either the right or the left pointer such that it increases the
         *  next subarray's localSum.
         */
        int maxSum = accumulate(nums.begin(), nums.end(), 0);
        int localSum = maxSum;
        int leftPtr = 0;
        int rightPtr = nums.size() - 1;

        while (leftPtr < rightPtr)
        {
            int leftPtrShiftSum = localSum;
            int rightPtrShiftSum = localSum;

            // sumOf subarray if shift leftPtr
            leftPtrShiftSum = localSum - nums[leftPtr];
            // sumOf subarray if shift rightPtr
            rightPtrShiftSum = localSum - nums[rightPtr];
            // shift ptr in direction w/ largest sumOf subarray, update localSum
            if (leftPtrShiftSum > rightPtrShiftSum)
            {
                leftPtr++;
                localSum = leftPtrShiftSum;
            } else
            {
                rightPtr--;
                localSum = rightPtrShiftSum;
            }
            // update maxSum
            maxSum = max(localSum, maxSum);
        }
        return maxSum;
    }
};
// @lc code=end

