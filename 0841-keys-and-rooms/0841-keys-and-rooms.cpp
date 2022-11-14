class Solution {
public:
    void bfs(int i, vector<int> &vis, vector<int> adj[]){
        queue<int> que;
        que.push(i);
        vis[i] = 1;
        
        while(!que.empty()){
            int n= que.size();
            
            for(int i=0; i<n; i++){
                int node = que.front();
                que.pop();
                
                for(int& it: adj[node]){
                    if(vis[it]== -1){            //not visited
                        vis[it] = 1;
                        que.push(it);
                    }
                }
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> adj[n];
        
        //prepare adj list
        for(int i=0; i<n; i++){
            for(auto& jt: rooms[i]){
                adj[i].push_back(jt);
            }
        }
        
        
        //BFS
        vector<int> vis(n, -1);
        vis[0] = 1;
        for(auto& it: rooms[0]){        //we have only access to room1
            if(vis[it]==-1)
                bfs(it, vis, adj);
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