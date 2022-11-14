class Solution {
public:
    void bfs(int i, vector<int> &vis, vector<vector<int>>& rooms){
        queue<int> que;
        que.push(i);
        vis[i] = 1;
        
        while(!que.empty()){
            int n= que.size();
            
            for(int i=0; i<n; i++){
                int node = que.front();
                que.pop();
                
                for(auto& it: rooms[node]){
                    if(vis[it]== -1){            //not visited
                        vis[it] = 1;
                        que.push(it);
                    }
                }
            }
        }
    }
    
    //do graph traversal(BFS) and use rooms as adj[] list
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> adj[n];
        
        
        //BFS
        vector<int> vis(n, -1);
        vis[0] = 1;
        for(auto& it: rooms[0]){        //we have only access to room1
            if(vis[it]==-1)
                bfs(it, vis, rooms);
        }
        
        //check whether all gates are travelled
        for(int i=0; i<n; i++)
        {
            if(vis[i]==-1)          //any gate is not visited
                return false;
        }
        
        return true;
    }
};