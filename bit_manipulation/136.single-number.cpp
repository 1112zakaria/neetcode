/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Axiom 1: if a ^ b == 0, then a == b, otherwise a != b
     * Axiom 2: every element appears twice except for one
     * 
     * Approach: perform xor operation on all numbers. All the
     * duplicate numbers will cancel each other out and there
     * will only be the non-duplicate number left
     */
    int singleNumber(vector<int>& nums) {
        int output = 0;
        for (int num : nums)
        {
            output = output ^ num;
        }
        return output;
    }
};
// @lc code=end

