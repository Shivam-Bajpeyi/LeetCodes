//Number of components: use bfs/dfs graph traversal
class Solution {
public:
    void dfs(int i, vector<int> &vis, vector<int> adj[]){
        vis[i] = 1;
        
        for(auto& it: adj[i]){
            if(vis[it]==-1)
                dfs(it, vis, adj);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        //make adj list
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]==1)
                    adj[i].push_back(j);        //1-> (2)
            }
        }  
        
        //dfs
        int ans = 0;
        vector<int> vis(n, -1);
        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                dfs(i, vis, adj);
                ans++;              //number of components
            }     
        }
        
        return ans;
    }
};