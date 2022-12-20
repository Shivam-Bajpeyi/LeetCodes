class Solution {
public:  
    void dfs(int node, vector<int> &vis, vector<vector<int>>& rooms){
        vis[node] = 1;
        
        for(auto &it: rooms[node]){
            if(vis[it]==-1){
                dfs(it, vis, rooms);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //do Graph trversal (dfs/bfs) from 0 to see whether all nodes can be visited 
        int n = rooms.size();
        vector<int> vis(n, -1);
        
        //dfs
        dfs(0, vis, rooms);
        
        //check whether all node visited?
        for(auto &it: vis){
            if(it==-1)
                return false;
        }
        
        return true;
    }
};