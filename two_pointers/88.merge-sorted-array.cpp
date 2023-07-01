/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Approach #1 (Bubble sort, O(n^2)):
     * - iterate nums1 and nums2, whenever nums2 > nums1,
     * add nums2 into nums1 and shift all the nums1 values
     * 
     * Approach #2 (Append+sort, O(nlogn)):
     * - append nums2 to nums1 and then sort
     * 
     * Approach #3 (xxx, attempted O(n), but risks being O(n^2)):
     * - init pointer at end of nums1, nums2, & curr @ nums2
     *      - nums1: end of nums1 arr (@ pos m)
     *      - nums2: end of nums2 arr (@ pos n)
     *      - curr: end of capacity for nums1 (@ pos m+n)
     * - for each val in nums2, going backward:
     *      - compare end of nums2 w/ end of nums1:
     *          - if nums2 >= nums1, place nums2 at curr, decrement curr
     *          - if nums2 < nums1, place nums1 at curr, place nums2 at nums1's old pos
     *          and decrement curr
     *              - + shift nums2 until it is someplace where sorted prop is valid
     *              - .. TBD
     * 
    */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1P, n2P, currP;
        n1P = m - 1;
        n2P = n - 1;
        currP = m + n - 1;
        
        while (n1P >= 0 && n2P >= 0) {
            if (nums1[n1P] >= nums2[n2P]) {
                nums1[currP] = nums1[n1P];
                n1P--;
            } else {
                nums1[currP] = nums2[n2P];
                n2P--;
            }
            currP--;
        }

        while (n2P >= 0) {
            nums1[currP] = nums2[n2P];
            n2P--;
            currP--;
        }
    }
};
// @lc code=end

