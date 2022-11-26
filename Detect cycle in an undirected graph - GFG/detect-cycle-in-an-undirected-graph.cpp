//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Using BFS: push nodes in queue in (node, parent) fashion
class Solution {
  private:
  //function to bfs traverse on graph to detect cycle
    bool bfs(int node, vector<int>& vis, vector<int> adj[]){
        vis[node] = 1;
        queue<pair<int, int>> q;
        q.push({node, -1});
        
        //bfs
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                auto topp = q.front();
                q.pop();
                int node = topp.first;
                int parent = topp.second;
                
                //if neighbour is visited by some other node, then its a cycle
                for(auto& it: adj[node]){
                    if(it!= parent)  //visit adj except parent
                    {
                        if(vis[it]==1)
                            return true;
                        else{
                            vis[it]= 1;
                            q.push({it, node});
                        }
                    }
                }
            }
        }
        
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int N, vector<int> adj[]) {
        vector<int> vis(N, -1);
        
        //bfs
        for(int i=0; i<N; i++){
            if(vis[i]==-1 && bfs(i, vis, adj))
                return true;
        }
    
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends