/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
static bool compare(const vector<int> &i, const vector<int> &j) {
    return i[0] < j[0];
}

class Solution {
public:
    /**
     * Approach #1 (sort, O(nlogn)):
     * - objective: sort and then merge overlapping intervals
     * - iterate each pair in the sorted list
     * - init output list with first element and define currStart/currEnd
     * - for each pair,
     *      - if its start is less than currEnd, set currEnd to end
     *      - if start is greater than currEnd, add new pair to output
     *      and update currStart/currEnd to new pair
     * 
     * 
     * Approach #2 (map, O(n), O(n)):
     * - goal is to map start of non-overlapping intervals to their end
     * - when an overlap is detected, 
     * - map intervals by start value
     * - join interv
     * - ...
    */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int start, tail;
        vector<vector<int>> out = vector<vector<int>>();
        vector<int> localPair;

        sort(intervals.begin(), intervals.end(), compare);
        start = intervals[0][0];
        tail = intervals[0][1];

        for (vector<vector<int>>::iterator i = begin(intervals)+1; i != end(intervals); ++i) {
            localPair = *i;
            if (localPair[0] <= tail) {
                tail = max(localPair[1], tail);
            } else {
                // 
                out.push_back({start, tail});
                start = localPair[0];
                tail = localPair[1];
            }
        }
        out.push_back({start, tail});
        return out;
    }

};
// @lc code=end

