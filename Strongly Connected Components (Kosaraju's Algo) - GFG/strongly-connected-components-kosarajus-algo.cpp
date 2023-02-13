//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	private:
	//to store nodes acc to finishing time
	void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st){
	    vis[node] = 1;

	    for(auto &it: adj[node]){
	        if(vis[it] == -1){
	            dfs(it, vis, adj, st);
	        }
	    }
	    st.push(node);
	}
	
	//to explore the scc one by one
	void dfs2(int node, vector<int> &vis, vector<int> adj[]){
	    vis[node] = 1;

	    for(auto &it: adj[node]){
	        if(vis[it] == -1){
	            dfs2(it, vis, adj);
	        }
	    }
	}
	
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &graph)
    {
        vector<int> adj[V];
        for(int i=0; i<V; i++){
            for(auto &it: graph[i]){
                adj[i].push_back(it);
            }
        }
        
        //visited
        vector<int> vis(V, -1);
        
        //step-1: sort nodes in stack acc to finishing time so that scc1 nodes will be
        //stored at the top in stack
        stack<int> st;
        for(int i=0; i<V; i++){
            if(vis[i] == -1)
                dfs(i, vis, adj, st);
        }
        

        //step-2: reverse the graph
        vector<int> reverseAdj[V];
        for(int i=0; i<V; i++){
            vis[i] = -1;
            for(auto &it: adj[i]){
                reverseAdj[it].push_back(i);
            }
        }
        
        
        //step-3: DFS to count scc acc to node stored ------>
        int cnt = 0;
        while(!st.empty()){
            int i = st.top();
            st.pop();
            
            if(vis[i] == -1){
                cnt++;
                dfs2(i, vis, reverseAdj);
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends