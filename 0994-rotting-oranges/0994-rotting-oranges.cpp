class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //number of total and rotten oranges
        int total=0, n= grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != 0) total++;
                if(grid[i][j]==2) q.push({i, j});
            }
        }
        
        //bfs 
        int minutes= -1, rotten=0;
        int size = q.size();
        while(!q.empty()){
            ++minutes;
            int size = q.size();
            rotten += size;           //total oranges we rotten
            
            while(size--){
                int row = q.front().first;
                int col = q.front().second;
                // cout<<row<<" "<<col<<endl;
                q.pop();
                
                //do needfull for neighbours(fresh oranges)
                if(row-1>=0 && grid[row-1][col]==1){    //up
                    q.push({row-1, col});
                    grid[row-1][col] = 2;
                } 
                if(row+1<grid.size() && grid[row+1][col]==1){   //down
                    q.push({row+1, col});
                    grid[row+1][col]=2;
                } 
                if(col-1>=0 && grid[row][col-1]==1) {   //left
                    grid[row][col-1]=2;
                    q.push({row, col-1});
                }
                if(col+1 <grid[0].size() && grid[row][col+1]==1) {  //right
                    q.push({row, col+1});
                    grid[row][col+1]= 2;
                } 
            }
        }
        
        
        //no orange, no time
        if(total==0) return 0;
        
        //if there are check whether we rotten all or not
        if(rotten== total)
            return minutes;
        return -1;
    }
};