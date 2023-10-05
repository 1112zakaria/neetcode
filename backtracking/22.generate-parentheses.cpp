/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Approach (brute force/backtracking, O(2^n)):
     * - rule: you cannot have more closed parentheses than open
     * - rule: you can have max n open and n closed parentheses
     * - maintain a "stack" of parentheses.
     *      - you need an open parenthesis to add a closed parenthesis,
     *      then you can pop the back two
     *      - if you cannot do this, then it is invalid
     * - by the end of the backtracking, the stack should be empty of open
     * and closed parentheses
     *      - adding a closed parenthesis should subtract an open parenthesis
     * - maintain list of valid parentheses
     * - every recursive call should try adding closed and open parentheses
     * 
     * Approach (recursive DFS, O(n)):
     * Rules:
     * - closed <= open
     * - open <= n
     * - closed <= n
     * - maintain output and stack
     * - 
    */
    vector<string> generateParenthesis(int n) {
        vector<char> stack;
        vector<string> output;
        helper(n, 0, 0, stack, output);
        return output;
    }

private:
    void helper(int n, int open, int closed, vector<char> &stack, vector<string> &output) {

        // base case:
        if (open == n && closed == n) {
            output.push_back(string(stack.begin(), stack.end()));
            return;
        }

        // recursive case:
        // add open
        if (open < n) {
            stack.push_back('(');
            helper(n, open+1, closed, stack, output);
            stack.pop_back();
        }

        // add closed
        if (closed < open && closed < n) {
            stack.push_back(')');
            helper(n, open, closed+1, stack, output);
            stack.pop_back();
        }
        return;
    }
};
// @lc code=end

