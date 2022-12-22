class Solution {
public:
    vector<vector<int>> graph;
    vector<int> sons_cnt;
    vector<int> subtree_ans;
    vector<int> answer;

    int DFS_sons(int node, int parent, int sons) {
        int tmp_sons = sons;

        for (auto elem : graph[node]) 
            if (elem != parent)
                sons += DFS_sons(elem, node, tmp_sons) + 1;

        sons_cnt[node] = sons;
        return sons;
    }

    int DFS_subtree_ans(int node, int parent, int dist) {
        for (auto elem : graph[node]) {
            if (elem != parent) {
                subtree_ans[node] += DFS_subtree_ans(elem, node, dist+1);
                subtree_ans[node] += 1 + sons_cnt[elem];
            }
        }
        return subtree_ans[node];
    }

    void DFS_ans(int node, int parent, int n) {
        if (parent == -1)
            answer[node] = subtree_ans[node];
        else
            answer[node] = answer[parent] + n - 2 * sons_cnt[node] - 2;

        for (auto elem : graph[node])
            if (elem != parent)
                DFS_ans(elem, node, n);
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        for (int i=0; i<n; i++) {
            graph.push_back({});
            answer.push_back(0);
            sons_cnt.push_back(0);
            subtree_ans.push_back(0);
        }
        for (auto elem : edges) {
            graph[elem[0]].push_back(elem[1]);
            graph[elem[1]].push_back(elem[0]);
        }

        DFS_sons(0, 0, 0);

        DFS_subtree_ans(0, 0, 0);

        DFS_ans(0, -1, n);

        return answer;
    }
};