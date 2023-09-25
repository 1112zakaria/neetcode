/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */
#include <vector>
#include <string>
#include <set>
using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Approach: O(), backtracking
     * - for every square, check that the letter matches the current target
     * letter and then check to see if you can traverse up, down, left, or right
     * - since you cannot iterate over the same square, keep track of a set of 
     * already traversed square-coordinates
     * - return true if word_idx >= len(word)
    */
    bool exist(vector<vector<char>>& board, string word) {
        set<vector<int>> init_traversed;
        
        for (int j=0; j<board.size(); j++) {
            for (int i=0; i<board[0].size(); i++) {
                if (helper(board, word, 0, init_traversed, 0, 0)) {return true;}
            }
        }
        
        return false;
    }

private:
    bool helper(vector<vector<char>> &board, string &word, int word_idx, set<vector<int>> traversed, int x, int y) {
        bool result = false;
        set<vector<int>> local_traversed;
        // // base case: all letters of word have been found
        // if (word_idx >= word.size()) {
        //     return true;
        // }

        // base case: letter is not part of what we are looking for, stop search
        if (word[word_idx] != board[y][x]) {
            return false;
        }

        // base case: all letters of word have been found
        if (word_idx == word.size()-1) {
            return true;
        }
        word_idx += 1;

        local_traversed = traversed; // copy of traversed set
        local_traversed.insert({x,y});

        // traverse up if not traversed
        if (y - 1 >= 0 && local_traversed.find({x,y-1}) == local_traversed.end()) {
            result |= helper(board, word, word_idx, local_traversed, x, y-1);
        }

        // traverse right if not traversed
        if (x+1 < board[0].size() && local_traversed.find({x+1,y}) == local_traversed.end()) {
            result |= helper(board, word, word_idx, local_traversed, x+1, y);

        }

        // traverse left if not traversed
        if (x-1 >= 0 && local_traversed.find({x-1,y}) == local_traversed.end()) {
            result |= helper(board, word, word_idx, local_traversed, x-1, y);

        }

        // traversed down if not traversed
        if (y + 1 < board.size() && local_traversed.find({x,y+1}) == local_traversed.end()) {
            result |= helper(board, word, word_idx, local_traversed, x, y+1);

        }

        return result;
    }
};
// @lc code=end

