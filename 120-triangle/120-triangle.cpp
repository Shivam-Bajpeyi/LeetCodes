//DP- memoization solution

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), m = triangle[0].size();
        
        //step-1
        vector<vector<int>> dp(n, vector<int>(n, -1));  //initialized to 0
        return f(0, 0, n, triangle, dp);
    }
    
    int f(int i, int j, int row, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        if(i==row-1)
            return triangle[i][j];
            
        //step-3: return value if it is calculated previously
        if(dp[i][j] != -1) return dp[i][j];
        
        //step-2
        int move1 = triangle[i][j] + f(i+1, j, row, triangle, dp);
        int move2 = triangle[i][j] + f(i+1, j+1, row, triangle, dp);
        
        //store minimal value
        return dp[i][j] = min(move1, move2);;
    }
};