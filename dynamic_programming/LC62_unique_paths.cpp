// Problem Link: https://leetcode.com/problems/unique-paths/description/

// Solution: This problem can be solved using dynamic programming. The idea is to use a 2D array to store the number of unique paths to reach each cell in the grid. The number of unique paths to reach a cell (i, j) is the sum of the unique paths to reach the cell directly above it (i-1, j) and the cell directly to the left of it (i, j-1).

class Solution {
public:
    int pathCheck(int m,int n,int i,int j,vector<vector<int>>&dp){
        if(i>=m||j>=n) return 0; // check if the current cell is out of bounds
        if(i==m-1&&j==n-1) return 1; // check if the current cell is the destination cell
        if(dp[i][j]) return dp[i][j]; // return the stored value if it has already been computed
        return dp[i][j]=pathCheck(m,n,i+1,j,dp)+pathCheck(m,n,i,j+1,dp); // go for recursion and store the result in dp array
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        return pathCheck(m,n,0,0,dp);
    }
};