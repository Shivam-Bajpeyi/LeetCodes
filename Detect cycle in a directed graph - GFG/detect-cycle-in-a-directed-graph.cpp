//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        //step-1: store Indegree of each node in queue
	    vector<int> inDegree(V, 0);
	    queue<int> q;
	    for(int i=0; i<V; i++){
	        for(auto &it: adj[i]){
	            inDegree[it]++;
	        }
	    }
	    
	    //step-2: push nodes which have inDegree 0
	    for(int i=0; i<V; i++){
	        if(inDegree[i]==0)
	            q.push(i);
	    }
	    
	    //BFS
	    vector<int> ans;
	    while(!q.empty()){
            int node = q.front();
	        ans.push_back(node);
	       // cout<<node<<endl;
	        q.pop();
	            
	        for(auto &it: adj[node]){
	            --inDegree[it];
	            if(inDegree[it] == 0)
	                q.push(it);
	            
	        }
	    }
	    
	    //if the topo sort is ready: this graph is acyclic
	    if(ans.size() == V)     //no cycle: DAG - Directed Acylic Graph
	        return false;
	    return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends