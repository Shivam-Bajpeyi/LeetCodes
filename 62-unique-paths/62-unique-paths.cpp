class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return f(m-1, n-1, dp);
    }
    
    int f(int i, int j,  vector<vector<int>> &dp){
        //out of the boundary
        if(i<0 || j<0) 
            return 0;   //0-> this is not a path
        
        if(i==0 && j==0)
            return 1;   //got 1 path
        
        if(dp[i][j] != -1) return dp[i][j];
        
        //do all possible moves
        int left = f(i, j-1, dp);
        int up   = f(i-1, j, dp);
        
        //all ways= sum
        return dp[i][j] = left + up;
    }
};