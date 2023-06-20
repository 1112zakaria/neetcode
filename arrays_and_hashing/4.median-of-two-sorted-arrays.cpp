/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Approach #1:
     * - note:
     *      - both arrays are sorted
     *      - time complexity should be O(log (m+n))
     *      - if m+n is even, return the average of the two medians
     * - summary: on every iteration, pop the smallest and the largest values
     * until m+n <= 2
     * Approach #2:
     * - for both lists, point to the middle-most value, mid_a, mid_b
     * - cases:
     *      - mid_a > mid_b:
     *      - mid_b < mid_a:
     *      - mid_a == mid_b:
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return findMedianSortedArraysA(nums1, nums2);
    }

    double findMedianSortedArraysA(vector<int> &nums1, vector<int> &nums2) {
        vector<int> *remaining_nums;

        while (nums1.size() + nums2.size() > 2) {
            // Remove smallest
            if (nums1[0] <= nums2[0]) {
                nums1.erase(nums1.begin());
            } else {
                nums2.erase(nums2.begin());
            }

            // Remove largest
            if (nums1[nums1.size()-1] >= nums2[nums2.size()-1]) {
                nums1.pop_back();
            } else {
                nums2.pop_back();
            }
        }

        if (nums1.size() > 0 && nums2.size() > 0) {
            // There's an element in nums1 and an element in nums2
            return (nums1[0] + nums2[0]) / 2;
        }

        // There's elements either in nums1 or nums2
        if (nums1.size() > 0) {
            remaining_nums = &nums1;
        } else {
            remaining_nums = &nums2;
        }

        if (remaining_nums->size()) {
            //return (remaining_nums[0] + remaining_nums[1]) / 2;
            return (remaining_nums->at(0) + remaining_nums->at(1)) / 2;
        } else {
            return remaining_nums->at(0);
        }
    }
};
// @lc code=end

