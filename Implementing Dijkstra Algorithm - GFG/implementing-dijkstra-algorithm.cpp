//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //step-1: make a priority queue (Min- Heap) and push (0, Src) in it 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});    //(dist, src)
        
        //step-2: make a dist array with +I 
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        
        //step-3: extract top element and see if getting min dist for any adjacent node
        //then update dist for that node and push (dist, adjaceneNode) in pq
        while(!pq.empty()){
            int dis = pq.top().first;       //min dist node will be on top
            int node = pq.top().second;
            pq.pop();
            
            for(auto &it: adj[node]){
                int adjacentNode = it[0];
                int weight  = it[1];
                
                //if getting min dist, update & push
                if(dis+ weight < dist[adjacentNode]){
                    dist[adjacentNode] = dis + weight;
                    pq.push({dist[adjacentNode], adjacentNode});
                }
            }
        }
        
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends