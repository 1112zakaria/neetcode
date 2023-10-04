/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

#include <vector>
#include <set>

using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Approach (?, O(?)):
     * - iterate list of elements, store in map with value
     * as key and...
     * - Note: you are supposed to use the set datastructure
     * - Iterate every element, store in set
     * - problem: i dont want to iterate in every element, that would
     * balloon time complexity up to O(n^2), traverse only starting elements
     * of a sequence, which we can identify by checking that i-1 does not exist
     * in set
     * - Foreach element,
     *      - traverse the starting element and update the max longest
     *      consecutive sequence
     *     
    */
    int longestConsecutive(vector<int>& nums) {
        int lcs = 0, curr, local_lcs;
        set<int> nums_set;

        for (int num : nums) {
            nums_set.insert(num);
        }

        for (int num : nums_set) {
            // traverse only start element
            local_lcs = 1;
            if (nums_set.find(num - 1) == nums_set.end()) {
                curr = num + 1;
                while (nums_set.find(curr) != nums_set.end()) {
                    curr++;
                    local_lcs++;
                }
            }

            lcs = max(lcs, local_lcs);
        }
        return lcs;
    }
};
// @lc code=end

