//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    //prims algo = Vis[] + pq(min)
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //priority- queue(min- heap) to pick min weight always
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});    //(wt, node)
        
        //visited array
        vector<int> vis(V);
        
        int mstWeight = 0;
        while(!pq.empty()){
            //take out min weight edge 
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if(vis[node]==1) continue;
            
            //adding edge to mst
            vis[node]= 1;           //visited
            mstWeight += wt;        //sum up weights of mst
            
            for(auto &it: adj[node]){
                int adjacentNode = it[0];
                int wt = it[1];
                
                if(!vis[adjacentNode])
                    pq.push({wt, adjacentNode});
            }
        }
        
        return mstWeight;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends