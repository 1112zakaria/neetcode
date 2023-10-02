/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Approach (binary search, O(logn)):
     * - goal: find value target in the matrix
     * - hint: can use binary search, both using the first value in the
     * row and the values in the row
     * - we know that target is going to be in a row where row_head <= target
     * or it won't exist at all
     * - "searching inter-row":
     *      - if target < row_head: search lower row
     *      - if target > row_head: search row, if fail, search higher row
     *      - if target == row_head: return true
     * - "searching within-row":
     *      - if target > tail_val: fail, its out of range
     *      - binary search the row
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start, end, middle; // start, end, and middle are the exact array indices
        int row_head;
        bool result = false;

        start = 0;
        end = matrix.size() - 1;
        middle = getMidpoint(start, end);

        // Binary search the row heads
        while (start <= end && !result) {
            cout << "middle: " << middle << " start: " << start << " end: " << end << "\n";
            row_head = matrix[middle][0];

            if (target == row_head) {
                result = true;
            }
            if (target < row_head) {
                // search lower row
                end = middle - 1;
                middle = getMidpoint(start, end);
            }
            if (target > row_head) {
                // search row, if fail then search higher row
                if (searchRow(matrix[middle], target)) {
                    result = true;
                }

                start = middle + 1;
                middle = getMidpoint(start, end);
            }
            
        }

        return result;

    }

private:
    bool searchRow(vector<int> &row, int target) {
        // binary search of row
        int tail = row[row.size() - 1];
        int  start, end, middle;
        
        if (target > tail) {
            return false;
        }

        start = 0;
        end = row.size() - 1;
        middle = getMidpoint(start, end);

        while (start <= end) {
            if (row[middle] == target) {
                return true;
            }
            if (target < row[middle]) {
                // search value below
                end = middle - 1;
                middle = getMidpoint(start, end);
            }
            if (target > row[middle]) {
                // search value above
                start = middle + 1;
                middle = getMidpoint(start, end);
            }
        }
        return false;
    }

    int getMidpoint(int start, int end) {
        return start + (end - start) / 2;
    }
};
// @lc code=end

