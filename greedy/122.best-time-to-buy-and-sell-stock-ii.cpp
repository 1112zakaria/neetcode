/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Approach:
     * - what is this problem asking for? a set of price ranges
     * that do not overlap and that produce max profit
     * - you want to get the sum of all the climbing slopes
     * Approach 1 (Greedy, O(n), O(1)):
     * - start from the right of the array, keep track of two pointers:
     *      - maxSell, curr
     * - init maxSell to last addr, curr to 2nd last value
     * - when *curr > *maxSell, update maxSell
     * - when *curr < *maxSell, 
     *      - add (*maxSell-*curr),
     *      - update maxSell to curr
     * - return sum
     * - QUESTION: why start backwards instead of forward?
    */
    int maxProfit(vector<int>& prices) {
        int curr = prices.size() - 2;
        int maxSell = curr + 1;
        int maxProfit = 0;

        while (curr >= 0) {
            if (prices[curr] < prices[maxSell]) {
                maxProfit += prices[maxSell] - prices[curr];
            }
            maxSell = curr;
            curr--;
        }
        return maxProfit;
    }
};
// @lc code=end

