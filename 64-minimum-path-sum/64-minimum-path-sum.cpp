//DP_tabulation (bottom- up approach)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1)); //step1
        
        //build dp from values calculated initially
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 && j==0) dp[i][j]= grid[0][0];
                
                else{
                    int up = grid[i][j];            //go up, consider current value in sum
                    if(i>0)  
                        up+= dp[i-1][j];       //base cases
                    else 
                        up+= 1e6;
                    
                    int left = grid[i][j];         //go left, consider current value in sum
                    if(j>0) 
                        left += dp[i][j-1];   //base case
                    else
                        left += 1e6;
                    
                    cout<<min(up, left)<<endl;
                    dp[i][j] = min(up, left);
                
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};