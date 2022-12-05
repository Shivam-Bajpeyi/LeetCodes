class Solution {
public:
    bool dfs(int node, int color, vector<vector<int>>& graph, vector<int> &vis){
        // cout<<node<<" "<<color<<endl;
        vis[node] = color;
        
        //go to neighbours
        for(auto &it: graph[node]){
            if(vis[it]==-1)         //if not visited, color with opposite color
            {
                if(dfs(it, 1-color, graph, vis)==false)
                    return false;
            }
                
            
            //if colored then check
            else if(vis[it]==color){
                // cout<<node<<"->"<<color<<" "<<it<<"->"<<vis[it]<<endl;
                return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) { 
        // dfs
        vector<int> vis(graph.size(), -1);
        for(int i=0; i<graph.size(); i++){
            //if two adjacent nodes can't be colored with 2 diff colors
            if(vis[i]==-1 && dfs(i, 0, graph, vis)==false){
                return false;
            }
        }
        
        return true;
    }
};