// Problem Link: https://leetcode.com/problems/minimum-path-sum/description/

// Solution: This problem can be solved using dynamic programming. The idea is to use a 2D array to store the minimum path sum to reach each cell in the grid. The minimum path sum to reach a cell (i, j) is the value of the cell itself plus the minimum of the path sums to reach the cell directly above it (i-1, j) and the cell directly to the left of it (i, j-1).

// Tabulisation method: The space complexity is optimized to O(n) by using two 1D arrays instead of a 2D array. The time complexity is O(m*n) where m is the number of rows and n is the number of columns in the grid.

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> curr (cols, 0);
        vector<int> prev (cols, 0);
        int up, left, minval;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                
                up = INT_MAX;
                left = INT_MAX;

                if((i==0)&&(j==0)){
                    curr[j] = grid[i][j];
                    continue;
                }

                if(i>0){
                    up = prev[j];
                }
                if(j>0){
                    left = curr[j-1];
                }
                minval = grid[i][j] + min(up,left);
                curr[j] = minval;
            }
            prev = curr;
        }
        return prev[cols-1];
    }
};