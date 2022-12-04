class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<pair<int, int>> adj[], int &ans){
        vis[node] = 1;
        
        //go to neighbours
        for(auto &it: adj[node]){
            ans = min(ans, it.second);
            if(!vis[it.first]){ 
                dfs(it.first, vis, adj, ans);
            }
        }
    }
    
    
    int minScore(int n, vector<vector<int>>& roads) {        
        //make adj list
        vector<pair<int, int>> adj[n+1];
        for(auto &it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        vector<int> vis(n+1);
        int ans = INT_MAX;
        dfs(1, vis, adj, ans);
        
        return ans;
    }
};