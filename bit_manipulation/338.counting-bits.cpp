/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution
{
public:
    /**
     * Approach:
     * there's a repeating pattern of there being the same
     * patterns of bit movements used everytime there's a new
     * MSB, so include the solution of the lower bits + 1 to the current
     * solution...
     * (bad explanation becasue im shape rotating in my head whatever solution i saw online)
     *
     */
    vector<int> countBits(int n)
    {
        int msb;
        int offset;
        // does this get auto-deallocated when out of the function stack?
        vector<int> result;

        // solution:
        // sol[0] = 0
        // sol[i] = 1 + sol[offset], offset = i - (1 << msb)
        // keep track of msb and next_msb. when i == next_msb, msb = next_msb and next_msb = msb << 2
        result.push_back(0);
        msb = 0;
        for (int i = 1; i <= n; i++)
        {
            std::cout << "initial msb = " << msb << " ";
            if ( (1 << (msb + 1)) <= i)
            {
                msb++;
            }
            std::cout << "i = " << i << " msb = " << msb << std::endl;
            offset = i - (1 << msb);
            result.push_back(1 + result[offset]);
        }
        return result;
    }
};
// @lc code=end
