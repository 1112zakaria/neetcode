/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

#include <cstring>

// @lc code=start
class Solution {
public:
    /**
     * Approach #1 (DFS, O(2^n)):
     * - DFS at every node to the right and bottom.
     * Approach #2 (DP, O(n)):
     * - Initialize m x n grid to 0
     * - Iterate from left to right
     * - For every node, add the number of paths for the node above
     * and to the left
     * - Return the value at grid[m-1][n-1]
     * - Formula: grid[j][i] = grid[j-1][i] + grid[j][i-1]
     *      - compare the previous node elements
    */
    int uniquePaths(int m, int n) {
        int grid[m][n]; // m -> y, n -> x

        memset(grid, 0, sizeof(grid));
        grid[0][0] = 1;
        for (int j=0; j<m; j++) {
            for (int i=0; i<n; i++) {
                if (i-1 >= 0) {
                    grid[j][i] += grid[j][i-1];
                }
                if (j-1 >= 0) {
                    grid[j][i] += grid[j-1][i];
                }
            }
        }

        return grid[m-1][n-1];
    }
};
// @lc code=end

