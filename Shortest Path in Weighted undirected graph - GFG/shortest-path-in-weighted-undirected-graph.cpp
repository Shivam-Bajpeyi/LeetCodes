//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[n+1];
        for(auto i: edges) {
            int u = i[0], v = i[1], wt = i[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        //step-1: make a priority queue (Min- Heap) and push (0, Src) in it 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});    //(dist, src)
        
        //step-2: make a dist array with +I and parent array that will help for min path
        vector<int> dist(n+1, INT_MAX);
        dist[1] = 0;
        vector<int> par(n+1);
        par[1] = 1;
        
        //step-3: extract top element and see if getting min dist for any adjacent node
        //then update dist for that node and push (dist, adjaceneNode) in pq
        while(!pq.empty()){
            int dis = pq.top().first;       //min dist node will be on top
            int node = pq.top().second;
            pq.pop();
            
            for(auto &it: adj[node]){
                int adjacentNode = it.first;
                int weight  = it.second;
                
                //if getting min dist, update & push
                if(dis+ weight < dist[adjacentNode]){
                    dist[adjacentNode] = dis + weight;
                    pq.push({dist[adjacentNode], adjacentNode});
                    par[adjacentNode] = node;
                }
            }
        }
        
        if (dist[n] == INT_MAX)
            return {-1};
            
        //extract path from the last node 
        vector<int> res;
        int temp = n;
        while(par[temp] != temp){
            res.push_back(temp);
            temp = par[temp];
        }
        res.push_back(1);
        
        //path is stored in opoosite direction so reverse it
        reverse(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends