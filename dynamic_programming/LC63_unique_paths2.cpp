// Problem Link: https://leetcode.com/problems/unique-paths-ii/description/

// Solution: This problem can be solved using dynamic programming. The idea is to use a 2D array to store the number of unique paths to reach each cell in the grid, while considering obstacles. The number of unique paths to reach a cell (i, j) is the sum of the unique paths to reach the cell directly above it (i-1, j) and the cell directly to the left of it (i, j-1), but only if those cells are not obstacles.

// I have used the Tabulisation method to solve this problem. The space complexity is optimized to O(n) by using two 1D arrays instead of a 2D array. The time complexity is O(m*n) where m is the number of rows and n is the number of columns in the grid.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        // If the start cell itself is blocked, no path exists
        if (grid[0][0] == 1) return 0;

        int rows = grid.size();
        int cols = grid[0].size();

        // curr stores the number of ways for the current row
        // prev stores the number of ways for the previous row
        // zeros is used to reset curr for the next row iteration
        vector<int> curr(cols, 0);
        vector<int> prev(cols, 0);
        vector<int> zeros(cols, 0);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Start cell: only one way to be there (stay put)
                if (i == 0 && j == 0) {
                    curr[0] = 1;
                    continue;
                }

                // If the current cell is an obstacle, it cannot be used
                if (grid[i][j] == 1) {
                    curr[j] = 0;
                    continue;
                }

                // Number of ways to reach this cell = ways from above + ways from left
                int up = 0, left = 0;
                if (i > 0) {
                    up = prev[j];
                }
                if (j > 0) {
                    left = curr[j - 1];
                }
                curr[j] = up + left;
            }

            // Move the current row values to previous row for the next iteration
            prev = curr;
            curr = zeros;
        }

        // The answer is the number of ways to reach the bottom-right cell
        return prev[cols - 1];
    }
};