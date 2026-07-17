// Problem Link: https://leetcode.com/problems/triangle/description/

// Solution: This problem can be solved using dynamic programming. The idea is to use a 2D array to store the minimum path sum to reach each cell in the triangle. The minimum path sum to reach a cell (i, j) is the value of the cell itself plus the minimum of the path sums to reach the cell directly above it (i-1, j) and the cell directly to the left of it (i, j-1).

// Tabulisation method: The space complexity is optimized to O(n) by using two 1D arrays instead of a 2D array. The time complexity is O(m*n) where m is the number of rows and n is the number of columns in the triangle.

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        int cols = triangle[rows-1].size();
        if ((rows==1)&&(cols==1)) return triangle[0][0];
        vector<int> curr(cols,0);
        vector<int> prev(cols,0);
        int stup, adjup, result=INT_MAX;
        for (int i=0;i<rows;i++){
            for(int j=0;j<triangle[i].size();j++){
                stup = INT_MAX, adjup = INT_MAX;
                if((i==0)&&(j==0)){
                    curr[j] = triangle[i][j];
                    continue;
                }
                if(i>0){
                    if(j<(triangle[i].size()-1)){
                        stup = prev[j];
                    }
                    if(j>0){
                        adjup = prev[j-1];
                    }
                }
                curr[j] = triangle[i][j] + min(stup, adjup);
                if(i==(rows-1)){
                    result = min(result, curr[j]);
                }
            }
            prev = curr;
            fill(curr.begin(),curr.end(),0);
        }
        return result;
    }
};