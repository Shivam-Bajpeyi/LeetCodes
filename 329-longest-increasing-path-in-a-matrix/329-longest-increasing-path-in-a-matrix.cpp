class Solution {
public:
    int dir[5] = {1, 0, -1, 0, 1};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //DP: Store longest path for previous element in a matrix, so whenever we need we can use thet value to find largest path
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        
        int mx = 0; //this will store the largest path value   
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                mx = max(mx, helper(matrix, dp, i, j));  //find larget increasing path by taking all elements one by one in the matrix
            }
        }
        
        return mx+1;
    }
    
    int helper(vector<vector<int>>& matrix, vector<vector<int>>& dp, int r, int c){
        int row = matrix.size(), col  = matrix[0].size();
        
        if(dp[r][c] !=0)    //if we already know what is the length of the path from here
            return dp[r][c];
        
        //we need to find the largest path from this place
        //look out in all four directions, one by one if there is any greater element than this current element(matrix[r][c])
        for(int i=0; i<4; i++)
        {
            int newr = dir[i]+r;
            int newc = dir[i+1]+c;
            
            if(isValid(newr, newc, row, col) && matrix[newr][newc] > matrix[r][c])
                dp[r][c] = max(dp[r][c], 1+helper(matrix, dp, newr, newc));  //max path we need from all four directions
        }
                               
        return dp[r][c];
    }
    
    bool isValid(int r, int c, int R, int C){
        return (r>=0 && c>=0 && r<R && c<C);
    }    
    
};