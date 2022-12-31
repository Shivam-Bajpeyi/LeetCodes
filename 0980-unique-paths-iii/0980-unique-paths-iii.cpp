class Solution {
public:
    int dfs(int i, int j, int n, int m, int &cnt, int c, vector<vector<int>>& grid){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==-1 || grid[i][j]==3)
            return 0;
        
        if(grid[i][j]==2){
            if(cnt== c-1)
                return 1;
            return 0;
        }
        
        grid[i][j] = 3;
        
        //dfs
        int up = dfs(i-1, j, n, m, cnt, c+1, grid);
        int down = dfs(i+1, j, n, m, cnt, c+1, grid);
        int left = dfs(i, j-1, n, m, cnt, c+1, grid);
        int right = dfs(i, j+1, n, m, cnt, c+1, grid);
        
        grid[i][j] = 0;
        
        return up+down+left+right;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int s, e, cnt= 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    s= i; e=j;
                }
                else if(grid[i][j]==0)
                    cnt++;
            }
        }
        
        return dfs(s, e, n, m, cnt, 0, grid);
    }
};