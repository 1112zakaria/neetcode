/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Approach:
     * bit shift right 32 times and add +1 everytime LSB is set
     */
    int hammingWeight(int n) {
        int output = 0;
        for (int i=0; i<32; i++)
        {
            output += n & 1;
            n = n >> 1;
        }
        return output;
    }
};
// @lc code=end

