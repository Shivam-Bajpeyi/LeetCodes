//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void bfs(int node, vector<int> adj[], vector<int> & vis, vector<int> &res){
        res.push_back(node);
        vis[node] = 1;
        
        queue<int> q;
        q.push(node);
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(auto &it: adj[curr]){
                if(vis[it] == -1){
                    vis[it] = 1;
                    res.push_back(it);
                    q.push(it);
                }
            }
            
        }
    }
  
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        
        vector<int> vis(V, -1);
        
        //only for 0th node
        bfs(0, adj, vis, res);
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends