//BFS: color with 0 and 1, unvisited with  -1
class Solution {
public:
    bool bfs(int node, int color, vector<vector<int>>& graph, vector<int> &vis){
        // cout<<node<<" "<<color<<endl;
        queue<int> q;
        q.push(node);
        vis[node] = color;
        
        //go to neighbours
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                int it = q.front();
                q.pop();
                color = vis[it];
                // cout<<it<<endl;
                
                for(auto &jt: graph[it]){
                    if(vis[jt]==-1){         //if not visited, color with opposite color
                        vis[jt]= 1-color;
                        q.push(jt);
                    }
                
                    //if colored then check: 2 adj nodes have same color?
                    else if(vis[jt]==color){
                        return false;
                    }     
                }
                
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) { 
        // bfs
        vector<int> vis(graph.size(), -1);
        for(int i=0; i<graph.size(); i++){
            //if two adjacent nodes can't be colored with 2 diff colors
            if(vis[i]==-1 && bfs(i, 0, graph, vis)==false){
                return false;
            }
        }
        
        return true;
    }
};