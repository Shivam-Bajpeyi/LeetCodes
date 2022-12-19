class Solution {
public:
    bool bfs(int src, int dest, vector<int> &vis, vector<int> adj[]){
        vis[src] = 1;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                int node = q.front();
                q.pop();
                
                for(auto &it: adj[node]){
                    if(it == dest)
                        return true;
                    if(vis[it] == -1){
                        q.push(it);
                        vis[it] = 1;
                    }
                }
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
        
        //BFS
        vector<int> vis(n, -1);
        return bfs(src, dest, vis, adj);
    }
};