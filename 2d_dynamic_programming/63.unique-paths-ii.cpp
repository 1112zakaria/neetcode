/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int grid[m][n]; // m -> y, n -> x

        memset(grid, 0, sizeof(grid));
        if (obstacleGrid[0][0] == 0) {
            grid[0][0] = 1;
        }
        for (int j=0; j<m; j++) {
            for (int i=0; i<n; i++) {
                if (obstacleGrid[j][i] == 0) {
                    if (i-1 >= 0) {
                        grid[j][i] += grid[j][i-1];
                    }
                    if (j-1 >= 0) {
                        grid[j][i] += grid[j-1][i];
                    }
                }
            }
        }

        return grid[m-1][n-1];
    }
};
// @lc code=end

