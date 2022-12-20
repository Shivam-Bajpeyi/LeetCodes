class Solution {
public:
    void dfs(int node, vector<int> vis, vector<vector<int>>& graph, vector<int> temp){
        if(node == graph.size()-1){
            temp.push_back(node);
            ans.push_back(temp);
            return;
        }
        
        vis[node]= 1;
        temp.push_back(node);
        for(auto &it: graph[node]){
            if(vis[it] == -1){
                dfs(it, vis, graph, temp);
            }
        }
    }
    
    //store path vectors
    vector<vector<int>> ans;
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        dfs(0, vis, graph, {});
        
        return ans;
    }
};