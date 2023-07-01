/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Approach 1 (naive, O(n^2), O(1)):
     * - calculate all permutations and return the maximum start/end
     * day combo
     * Approach 2 (Dynamic programming/Memoization, O(n), O(n)):
     * - objective: foreach day, store the largest future price for each
     * day and then return the largest profit
     * Approach 3 (Sliding window, O(n), O(1)):
     * - ...
    */
    int maxProfit(vector<int>& prices) {
        return maxProfitDp(prices);
    }

    int maxProfitDp(vector<int> &prices) {
        if (prices.size() == 0) return 0;

        int maxProfit = 0;
        int maxSalePrice = prices[prices.size()-1];
        // calculate max sale price and max profit
        for (int i=prices.size()-2; i>=0; i--) {
            maxSalePrice = max(maxSalePrice, prices[i]);
            maxProfit = max(maxProfit, maxSalePrice - prices[i]);
        }
        return maxProfit;
    }
};
// @lc code=end

