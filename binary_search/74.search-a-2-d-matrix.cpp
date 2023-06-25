/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    /**
     * Approach:
     * - binary search the row headers
     * - before binary searching the rows, check that the last value is <= target
     * - todo: implement recursive and iterative approach (iterative preferred)
     * - define start, end, median header index
     * - search the median row
     * - cases:
     *      - if target >= median header and target exists in median row, return true
     *      - if target < median header, search median row to the left
     *      - if target > median header, search median row to the right
     *      - if median header <= target && target <= median tail, return searchRow(row, target)
     *      - if median header < target, return ser
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s_idx, e_idx, m_idx, median_header;
        bool target_exists = false;

        s_idx = 0;
        e_idx = matrix.size() - 1;

        while (!(e_idx < s_idx || s_idx > e_idx) && !target_exists) {
            m_idx = ceil( (e_idx - s_idx)/2 ) + s_idx;
            median_header = matrix[m_idx][0];
            target_exists = searchRow(matrix[m_idx], target);
            
            if (target > median_header) {
                s_idx = m_idx + 1;
            }
            else if (target < median_header) {
                e_idx = m_idx - 1;
            }
        }
        return target_exists;
    }

private:
    /**
     * Search row for target
     * Approach:
     * - check header, if target < header, return false
     * - check tail, if target > tail, return false
     * - binary search the row for target
    */
    bool searchRow(vector<int> &row, int target) {
        int s_idx, e_idx, m_idx, median;
        bool target_found = false;

        if (target < row[0] || target > row[row.size()-1]) return false;

        s_idx = 0;
        e_idx = row.size() - 1;

        while (s_idx <= e_idx && !target_found) {
            m_idx = ceil( (e_idx - s_idx)/2 ) + s_idx;
            median = row[m_idx];

            if (target == median) {
                target_found = true;
            }
            else if (target > median) {
                s_idx = m_idx + 1;
            }
            else if (target < median) {
                e_idx = m_idx - 1;
            }
        }
        return target_found;
    }
};
// @lc code=end

