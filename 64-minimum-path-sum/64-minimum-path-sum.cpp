//DP- memoization

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1)); //step1
        return f(n-1, m-1, grid, dp);
    }
    
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp){
        if(i==0 && j==0)    //return value if reached to goal 
            return grid[i][j];
        
        if(i<0 || j<0)  //don't consider this path so return a max value
            return 1e6;
        
        if(dp[i][j] != -1) return dp[i][j]; //step2
        
        int up   =  grid[i][j] + f(i-1, j, grid, dp);
        int left =  grid[i][j] + f(i, j-1, grid, dp);
        
        return dp[i][j] = min(up, left);   //take min sum(step3)
    }
};