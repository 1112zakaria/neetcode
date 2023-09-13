/*
 * @lc app=leetcode id=2848 lang=cpp
 *
 * [2848] Points That Intersect With Cars
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
static bool compareCoords(vector<int> i1, vector<int> i2) {
    return i1[0] < i2[0];
}

class Solution {
public:
    /**
     * Approach (naive, O(nlogn)):
     * - sort the list by start points
     * - keep track of a currStart,currEnd value, keep track of list of compressed start/end points
     * - iterate the sorted list:
     *      - if localStart <= currEnd and localEnd > currEnd: currEnd = localEnd
     *      - if localStart > currEnd, that means initialize new compressed range 
    */
    int numberOfPoints(vector<vector<int>>& nums) {
        int currStart, currEnd;
        int localStart, localEnd;
        int totalPoints = 0;
        
        // sort the list
        sort(nums.begin(), nums.end(), compareCoords);

        // iterate sorted list
        currStart = nums[0][0];
        currEnd = nums[0][1];
        totalPoints = currEnd - currStart + 1;
        for (int i=1; i<nums.size(); i++) {
            localStart = nums[i][0];
            localEnd = nums[i][1];
            if (localStart <= currEnd && localEnd > currEnd) {
                totalPoints += localEnd - currEnd;
                currEnd = localEnd;
            } else if (localStart > currEnd) {
                currStart = localStart;
                currEnd = localEnd;
                totalPoints += currEnd - currStart + 1;
            }
        }
        return totalPoints;

    }

};
// @lc code=end

