class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>>& graph, vector<int> &res){
        if(node == graph.size()-1){
            res.push_back(graph.size()-1);
            ans.push_back(res);
            return;
        }
        
        vis[node] = 1;
        res.push_back(node);
        for(auto &it: graph[node]){
            if(vis[it] == -1){
                dfs(it, vis, graph, res);
                vis[it] = -1;
                res.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        
        //dfs
        vector<int> res;
        dfs(0, vis, graph, res);
        return ans;
    }
};