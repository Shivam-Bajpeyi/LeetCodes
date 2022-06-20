//DP_tabulation (space- optimized)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        //store previous row to take care of dp[i-1][j] element
        vector<int> prev(m, -1); 
        
        //build dp from values calculated initially
        for(int i=0; i<n; i++){
            vector<int> curr(m, -1);   //stores current row
            for(int j=0; j<m; j++){
                if(i==0 && j==0) curr[j] = grid[i][j];
                
                else{
                    int up = grid[i][j];            //go up, consider current value in sum
                    if(i>0)  
                        up+= prev[j];       //add up previous row value
                    else 
                        up+= 1e6;
                    
                    int left = grid[i][j];         //go left, consider current value in sum
                    if(j>0) 
                        left += curr[j-1];   //base case
                    else
                        left += 1e6;
                    
                    // cout<<min(up, left)<<endl;
                    curr[j] = min(up, left);
                
                }
            }
            prev = curr;
        }
        
        return prev[m-1];
    }
};