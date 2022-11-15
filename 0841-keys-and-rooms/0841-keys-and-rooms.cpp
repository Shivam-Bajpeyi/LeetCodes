class Solution {
public:
    void dfs(int i, vector<int> &vis, vector<vector<int>>& rooms){      
        vis[i] = 1;
        
        //dfs
        for(auto& it: rooms[i]){
            if(vis[it]== -1){            //not visited
                dfs(it, vis, rooms);
            }
        }        
    }
    
    //do graph traversal(BFS) and use rooms as adj[] list
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        //dfs
        vector<int> vis(n, -1);
        vis[0] = 1;
        for(auto& it: rooms[0]){        //we have only access to room1
            if(vis[it]==-1)
                dfs(it, vis, rooms);
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