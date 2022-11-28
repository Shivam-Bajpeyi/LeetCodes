//--BFS with dp(store already calc distances)--
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        //vis[n][m] to know whether for this cell dist is calc or not
        //ans[n][m] to store the answer
        vector<vector<int>> ans(n, vector<int>(m)), vis(n, vector<int>(m, -1));
        
        //store the 0 cells with value 0 in queue as the dist is 0 for them
        queue<vector<int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({i, j, 0});      //[0][1]= pos, [2]= dist
                    vis[i][j] = 1;
                }
            }
        }
                                
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                auto topp = q.front();
                q.pop();
                int i = topp[0], j= topp[1], dist = topp[2];
                ans[i][j] = dist;
                
                //check in all 4 directions
                if(i-1>=0 && vis[i-1][j]==-1){
                    q.push({i-1, j, dist+1});
                    vis[i-1][j] = 1;
                } 
                if(i+1<mat.size() && vis[i+1][j]==-1) {
                    q.push({i+1, j, dist+1});
                    vis[i+1][j] = 1;
                } 
                if(j-1>=0 && vis[i][j-1]==-1) {
                    q.push({i, j-1, dist+1});
                    vis[i][j-1] = 1;
                } 
                if(j+1<mat[0].size() && vis[i][j+1]==-1) {
                    q.push({i, j+1, dist+1});
                    vis[i][j+1] = 1;
                } 
            }
        }
                                
        return ans;
    }
};