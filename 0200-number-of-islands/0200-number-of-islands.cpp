class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid){
        //out of boundary
        if(i<0 || j<0 || i>=grid.size() || j>= grid[0].size())
            return;
        
        if(grid[i][j]!='1')
            return;
        
        //traverse component
        grid[i][j]= '2';
        
        //dfs- check for land(1) in all 4 directions
        dfs(i-1, j, grid);      //up
        dfs(i+1, j, grid);      //down
        dfs(i, j-1, grid);      //left
        dfs(i, j+1, grid);      //right
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size(), m= grid[0].size(), cnt = 0;
        
        //count number of islands: components
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]== '1'){
                    // cout<<i<<" "<<j<<endl;
                    cnt+= 1;
                    dfs(i, j, grid);
                }
            }
        }
        
        return cnt;
    }
};