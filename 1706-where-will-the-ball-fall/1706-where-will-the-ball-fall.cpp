class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid){
        if(i>= grid.size())
            return j;           //from which col it will go out
        
        //left to right=> 1
        else if(grid[i][j]== 1 && j+1<grid[0].size() && grid[i][j+1]==1)
            return dfs(i+1, j+1, grid);
        
        //right to left=> -1
        else if(grid[i][j] == -1 && j-1>= 0 && grid[i][j-1]== -1)
            return dfs(i+1, j-1, grid);
        
        else
            return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> res(m);         //to store answer
        
        for(int j=0; j<m; j++){
            res[j] = dfs(0, j, grid);
        }
        
        return res;
    }
};