class Solution {
public:
    bool dfs(int node, int dest, vector<int> &vis, vector<int> adj[]){
        vis[node] = 1;
        
        for(auto &it: adj[node]){
            if(it == dest)
                return true;
            if(vis[it] == -1){
                if(dfs(it, dest, vis, adj)==true)
                    return true;
            }
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        if(src == dest)
            return true;
        
        //make adj list
        vector<int> adj[n];
        
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        //DFS
        vector<int> vis(n, -1);
        
        return dfs(src, dest, vis, adj);
    }
};