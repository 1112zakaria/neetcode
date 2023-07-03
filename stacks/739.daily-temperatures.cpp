/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

#include <vector>

using namespace std;

// @lc code=start
struct Temp {
    int day;
    int temp;
    Temp(int d, int t) {
        day = d;
        temp = t;
    };
    Temp() {

    };
};

class Solution {
public:
    /**
     * Approach #1 (Naive, O(n^2), O(n)):
     * - for each temperature, iterate over each subsequent temperature
     * until you identify one that is larger
     * 
     * Approach #2 (Stack, O(n), O(n)):
     * - initialize empty stack to contain local history of decreasing
     * temperature elements and their indices, tempHistory
     * - initialize list containing the future +ith days to wait until
     * temperature gets warmer, warmerDays
     * - iterate over each temperature, compare with top of stack until
     * temperature is less than or equal to top, then add to stack
     *      - keep popping while currTemp > top
     *      - if temp > stackTop, set tempHistory at stackTop.day to
     *      temp.day - stackTop.day
     * - return tempHistory
    */
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> warmerDays = vector<int>(temperatures.size(), 0);
        vector<Temp> tempHistory = vector<Temp>();
        Temp currTemp, stackTop;

        for (int i=0; i<temperatures.size(); i++) {
            currTemp = Temp(i,temperatures[i]);
            while (tempHistory.size() > 0 && tempHistory.back().temp < currTemp.temp) {
                // keep popping while currTemp > stackTop
                stackTop = tempHistory.back();
                warmerDays[stackTop.day] = currTemp.day - stackTop.day;
                tempHistory.pop_back();
            }
            tempHistory.push_back(currTemp);
        }
        return warmerDays;
    }
};
// @lc code=end

