class Solution {
public:
    void DFS(int node, int &visitedNodes, vector<int> &vis, vector<int> adj[], set<int> &st){
        vis[node] = 1;
        visitedNodes++;
        
        for(int it: adj[node]){   //call recursion calls for unvisited adjacent nodes
            if(vis[it]== -1 && !st.count(it)){
                DFS(it, visitedNodes, vis, adj, st);
            }
	            
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        //to check restricted node easily
        set<int> st;
        for(int it: restricted){
            st.insert(it);
        }
            
        //make adj[] list
        vector<int> adj[n], vis(n, -1); 
        
        for(auto &it: edges){
            // cout<<it[0]<<" "<<it[1]<<endl;
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        
        //DFS from node 0
        int visitedNodes = 0;
        DFS(0, visitedNodes, vis, adj, st);
        
                
        return visitedNodes;
    }
};