//BFS: walk from the boundary lands and substract it from total number of lands
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(), m= grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        
        //total land cells
        int total= 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]==1){
                    total++;
                
                    //boundary land cells
                    if(i==0 ||j==0|| i==n-1 || j==m-1){
                        q.push({i, j});  
                        vis[i][j]= 1;
                    }
                }     
            }
        }
        
        //see how many of them can be touched from boundary
        //BFS
        int touched= 0;
        while(!q.empty()){
            int sz = q.size();
            touched += sz;
            
            while(sz--){
                auto topp = q.front();
                q.pop();
                int i= topp.first;
                int j= topp.second;
                
                // cout<<i<<" "<<j<<endl;
                
                //4 dir
                if(i-1>=0 && vis[i-1][j]==-1 && grid[i-1][j]==1){
                    q.push({i-1, j});
                    vis[i-1][j] = 1;
                } 
                if(i+1<n && vis[i+1][j]==-1 && grid[i+1][j]==1){
                    q.push({i+1, j});
                    vis[i+1][j] = 1;
                } 
                if(j-1>=0 && vis[i][j-1]==-1 && grid[i][j-1]==1){
                    q.push({i, j-1});
                    vis[i][j-1]= 1;
                } 
                if(j+1<m && vis[i][j+1]==-1 && grid[i][j+1]==1){
                    q.push({i, j+1});
                    vis[i][j+1]= 1;
                } 
            }
        }

        
        return total- touched;
    }

};