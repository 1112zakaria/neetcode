/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Approach #1 (list and stack, O(n), O(n)):
     * - iterate string in reverse order, storing the letters
     * in a word in a stack
     * - once whitespace is detected, the word is appended to the list
     * of words
     * 
     * Approach #2 (list, no stack, O(n), O(n)):
     * - same thing, no stack, use ptrs?
    */
    string reverseWords(string s) {
        return helper(s);
    }

    string helper(string &s) {
        int start, end;
        string output = "";
        char letter;
        bool textDetected = false;

        if (s == "") {
            return "";
        }

        s = ' ' + s;

        end = s.size() - 1;
        start = end;

        while (start >= 0 && end >= 0) {
            letter = s[start];
            // whitespace detected
            if (letter == ' ') {
                // append current text w/ space if possible
                // note: need to detect if text
                if (textDetected) {
                    output.append(s.substr(start+1, end-start) + " ");
                    textDetected = false;
                    end = start;
                }

                // shift end and start ptrs
                end--;
                start = end;
            }
            else { // no whitespace
                // shift start ptr
                textDetected = true;
                start--;
            }
        }

        // append remaining text, in this case, remove training space
        
        return output.substr(0, output.size()-1);
    }
};
// @lc code=end

