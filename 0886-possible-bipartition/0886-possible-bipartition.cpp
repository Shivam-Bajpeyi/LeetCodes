class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<int> adj[], int color){
        vis[node] = color;
        
        for(auto &it: adj[node]){
            if(vis[it]==-1){
                if(dfs(it, vis, adj, 1-color)==false)
                    return false;
            }
            else if(vis[it] == color)
                return false;
        }
        
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        //bipartite graph
        vector<int> adj[n+1];
        for(auto &it: dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        //dfs
        vector<int> vis(n+1, -1);
        for(int i=1; i<=n; i++){
            if(vis[i]== -1 && dfs(i, vis, adj, 0)==false)
                return false;
        }
        
        return true;
    }
};