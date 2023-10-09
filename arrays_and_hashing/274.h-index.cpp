/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Approach #1 (hashing?):
     * 
     * Approach #2 (sort, O(nlogn)):
     * - sort the list of citations
     * - traverse from right to left
     * - foreach paper i,
     *      - check that the # citations is greater than or equal
     *      to the number of papers to its right + itself
     *      - return this # citations if true
     * - return 0? im not sure...
    */
    int hIndex(vector<int>& citations) {
        int numPapers = citations.size();

        sort(citations.begin(), citations.end());

        for (int i=numPapers-1; i>=0; i--) {
            if (numPapers - i >= citations[i]) {
                return citations[i];
            }
        }
        return numPapers;
    }
};
// @lc code=end

