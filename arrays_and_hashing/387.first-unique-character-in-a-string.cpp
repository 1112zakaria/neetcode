/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

#include <string>
#include <set>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Approach #1 (set, O(n), O(n)):
     * - store all elements in a set
     * - traverse string and return index of first element not in set
    */
    int firstUniqChar(string s) {
        map<char, int> letterCount;

        for (char c : s) {
            if (letterCount.find(c) == letterCount.end()) {
                // init
                letterCount[c] = 0;
            }
            letterCount[c]++;
        }

        for (int i=0; i<s.size(); i++) {
            if (letterCount[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

