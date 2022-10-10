class Solution {
public:
    int mod = 1e9+7;
    int n, m;
    
    int f(int i, int j, vector<vector<int>>& grid, int k, int sum,  vector<vector<vector<int>>> &dp){
        if(i>=n || j>=m) return 0;
        
        if(i==n-1 && j==m-1){
            sum+= grid[i][j];
            if(sum%k==0) return 1;
            return 0;
        }
             
        if(dp[i][j][sum%k] != -1) return dp[i][j][sum%k];
        
        //explore- down & right
        long down = f(i+1, j, grid, k, sum+grid[i][j], dp);
        long right = f(i, j+1, grid, k, sum+grid[i][j], dp);
        
        return dp[i][j][sum%k] = (down%mod+right%mod) %mod;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        
        //dp
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(k+1, -1)));
        return f(0, 0, grid, k, 0, dp);
    }
};