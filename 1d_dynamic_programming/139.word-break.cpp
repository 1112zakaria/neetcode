/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Approach #1 (backtracking w/ cache, O(?)):
     * - goal: identify whether a string can be segmented into
     * a sequence of one or more dictionary words
     * - recursively attempt to match each word dict starting from
     * the start
     * - if there is a match, check that the next possible start index
     * matches one of the dict words
     * - if there is no match starting from index i, mark that index in the
     * cache as having no matches to prevent further backtracking iterations
     * from repeating work
     * - base case: end of string idx was reached
     * - recursive case: checking substring for wordDict
     * - Q: when implementing cache, do I need to notify successes, or should
     * I just notify failures...
     *      - i want to notify when it is futile to keep searching, but do I want
     *      to notify whether a word has already been searched and skip straight to it?
    */
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> cache(s.size(), true);
        return helper(s, wordDict, 0, cache);
    }

private:
    bool helper(string &s, vector<string> &wordDict, int idx, vector<bool> &cache) {
        bool result = false, local_match = false;

        // base case:
        if (idx >= s.size()) {
            return true;
        }

        if (cache[idx] == false) {
            // if previous searches indicated that there was no result,
            // stop search immediately
            return false;
        }

        // recursive case: check substrings for wordDict match
        for (string word : wordDict) {
            if (idx + word.size() <= s.size() && s.substr(idx, word.size()) == word) {
                local_match = true;
                result = result || helper(s, wordDict, idx + word.size(), cache);
            }
        }

        if (!local_match) {
            // cache result of failing to find match at idx to cut the search space
            // for future iterations
            cache[idx] = false;
        }

        return result;
    }
};
// @lc code=end

