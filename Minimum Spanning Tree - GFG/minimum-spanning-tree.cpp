//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    public:
        vector<int> rank, par, size;
        
        DisjointSet(int n){
            rank.resize(n+1, 0);
            par.resize(n+1);
            size.resize(n+1, 1);
            
            //parent of a node is node itself
            for(int i=0; i<=n; i++){
                par[i] =  i;
            }
        }
        
        
        int findPar(int node){
            if(par[node] == node)
                return node;
                
            //path- compression    
            return par[node] = findPar(par[node]);
        }
        
        void unionByRank(int u, int v){
            int ul_u = findPar(u);
            int ul_v = findPar(v);
            
            if(ul_u == ul_v) return;
            
            //attach smaller to greater
            if(ul_u < ul_v){
                par[ul_u] = ul_v;       //u -> v
            }
            
            else if(ul_v< ul_u){
                par[ul_v] = ul_u;       //v -> u
            }
            
            else{
                par[ul_v] = ul_u;
                rank[ul_u]++;
            }
        }
        
        void unionBySize(int u, int v){
            int ul_u = findPar(u);
            int ul_v = findPar(v);
            
            if(ul_u == ul_v) return;
            
            //attach smaller to greater
            if(ul_u < ul_v){
                par[ul_u] = ul_v;
                size[ul_v] += size[ul_u];
            }
            
            //works for both condition (ul_v < ul_u) and equal
            else{
                par[ul_v] = ul_u;
                size[ul_u] += size[ul_v];
            }
            
        }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //step-1 sort edges by weight
        vector<pair<int, pair<int, int>>> edges;  //(wt, u, v)
        
        for(int i=0; i<V; i++){
            for(auto &it: adj[i]){
                int v = it[0];
                int wt = it[1];
                int u = i;
                
                edges.push_back({wt, {u, v}});
            }
        }
        
        sort(edges.begin(), edges.end());
        
        DisjointSet ds(V);
        
        int mstWeight = 0;
        for(auto &it: edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            //add the edge to mst if it is not forming cycle
            if(ds.findPar(u) != ds.findPar(v)){
                mstWeight += wt;
                ds.unionBySize(u, v);
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