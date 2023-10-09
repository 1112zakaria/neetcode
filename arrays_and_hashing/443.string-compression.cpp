/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Approach (, O(n)):
     * - traverse each char
     * - maintain a read and a write ptr
     * - foreach char, count the number of occurrences of
     * the current char until it changes
     *      - when the current char changes, write the compressed
     *      char data in-place to the string and start counting
     *      the new char
     * - once the read ptr has traversed all of the characters in the string,
     * we must now get rid of all the surplus characters
     *      - pop all chars in the string until the size is equal to the write_ptr
     *      idx
     * 
     * Problem: will i ever overwrite data that I will need
     * to read?
     * I might need two pointers? one to keep track of the current
     * write location and one for the current read location
     * Possible edge case: what if there's only 1 character? we would
     * need to make sure we don't overwrite data that needs to be read
     *      - also need to make sure memory is alloc'd for any new data needed
     * - Q: will i ever need to update the read ptr while writing? im not sure,
     * ill figure that out when i debug
     * Cases:
     *      - 1 char
     *      - 2 or more repeated chars
    */
    int compress(vector<char>& chars) {
        int write_ptr, read_ptr;
        char curr_char = chars[0], new_char;
        int curr_qty;
        int init_size = chars.size();

        write_ptr = 0;
        read_ptr = 0;
        curr_qty = 0;

        //for (char c : chars) {
        for (int idx=0; idx < init_size; idx++) {
            // FIXME: i might have to change this to index iteration
            char c = chars[idx];
            if (curr_char == c) {
                curr_qty++;  
            } else {
                // update curr_char, write old char in list, count new char
                // 
                new_char = c;
                write_ptr = write_compressed(chars, read_ptr, write_ptr, curr_qty, curr_char);

                curr_char = new_char;
                curr_qty = 1;
            }
            read_ptr++;
        }

        // write remaining char
        write_ptr = write_compressed(chars, read_ptr, write_ptr, curr_qty, curr_char);

        // clear excess memory if it exists
        while (chars.size() > write_ptr) {
            chars.pop_back();
        }
        return chars.size();
    }

private:
    int write_compressed(vector<char>& chars, int read_ptr, int write_ptr, int qty, char curr_char) {
        // returns the new write_ptr location
        // if qty is greater or equal to 10, make sure to write the number as 2 chars
        // FIXME: consider case where qty is 1 perhaps?
        // write character
        write_ptr = write(chars, write_ptr, curr_char);
        write_ptr = write_qty(chars, write_ptr, qty); // write qty
        return write_ptr;
    }

    int write_qty(vector<char> &chars, int write_ptr, int qty) {
        // modulo by 10, write the digit
        int val = qty;
        vector<char> digits;

        if (qty == 1) {
            return write_ptr;
        }

        while (val > 0) {
            // print modulo, then divide by 10
            // FIXME: this is cheating... violates the constant memory clause
            // how can I do this using constant memory
            digits.push_back('0' + (val % 10));
            val = val / 10;
        }

        for (int i=digits.size() -1; i>= 0; i--) {
            write_ptr = write(chars, write_ptr, digits[i]);
        }
        return write_ptr;
    }

    int write(vector<char> &chars, int write_ptr, char val) {
        if (write_ptr >= chars.size()) {
            chars.push_back('0');
        }
        chars[write_ptr] = val;
        write_ptr++;
        return write_ptr;
    }
};
// @lc code=end

