class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));      //stores no of paths at each point
        
        //return no. of unique paths
        return helper(obstacleGrid, dp, 0, 0);
    }
    
    int helper(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int i, int j){
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || obstacleGrid[i][j]==1) //out of boundary
             return 0;
        
        if(dp[i][j] != -1)      //if already have the valuem, use that to calc no of paths
            return dp[i][j];
        
        if(i==m-1 && j==n-1)    //if reached to correct pos, got 1 path
             return 1;
        
        //Now we need to calc the no of unique paths, in right and bottom direction
        return dp[i][j] = helper(obstacleGrid, dp, i, j+1) + helper(obstacleGrid, dp, i+1, j);
    }
};