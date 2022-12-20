class Solution {
public:  
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //do Graph trversal (dfs/bfs) from 0 to see whether all nodes can be visited 
        int n = rooms.size();
        vector<int> vis(n, -1);
        
        //bfs
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto &it: rooms[node]){
                if(vis[it]==-1){
                    vis[it]= 1;
                    q.push(it);
                }
            }
        }
        
        //check whether all node visited?
        for(auto &it: vis){
            if(it==-1)
                return false;
        }
        
        return true;
    }
};