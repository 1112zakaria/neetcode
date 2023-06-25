/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Approach:
     * - the max eating rate of bananas is k_max = max(piles)
     *      - this will eat all the bananas in piles.length time
     * - the min eating rate of bananas is constrained by the # of
     * hours h
     * - if koko could, she would want to eat all the bananas in h hours
     * - the goal of this problem is to find the number that lets you divide
     * the number of bananas, where the number of groups is as close as possible
     * to hours h
     * - sum(p[i]/k) <= h, 1 <= k_min <= max(piles) <-- this relationship must follow
     * - we need to search the values between 1 and h to identify k_min
     * - identify start, end, and median
     * - binary search through the test values of k until you find one where
     * or !(start <= end)
     * - foreach value k check that the relationship passes, 
     * - cases:
     *      - if test_k passes, search lower
     *      - if test_k fails, search higher
    */
    int minEatingSpeed(vector<int>& piles, int h) {
        int start, end, median, min_k;
        bool test_passed;
        
        start = 1;
        end = *max_element(piles.begin(), piles.end());
        min_k = end; // max_k
        
        if (piles.size() == h) return end;

        while (start <= end) {
            median = ceil( (end - start)/2 ) + start;
            test_passed = test_k_rate(piles, h, median);

            if (test_passed) {
                // search lower
                min_k = min(median, min_k);
                end = median - 1;
            }
            else {
                // search higher
                start = median + 1;
            }
        }
        return min_k;   
    }

private:
    bool test_k_rate(vector<int> &piles, int h, int test_k) {
        double sum_output = 0;
        for (int i=0; i<piles.size(); i++) {
            sum_output += ceil((double)piles[i] / test_k);
        }
        return sum_output <= h;
    }
 };

#if 0
int main() {
    Solution s;
    vector<int> piles{ 3, 6, 7, 11 };
    s.minEatingSpeed(piles, 8);
    return 0;
}
#endif
// @lc code=end

