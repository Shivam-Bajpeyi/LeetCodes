class Solution {
public:
    int dirs[6][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 0}, {1, 1}};

void dfs(vector<vector<int>> &grid, int x, int y, int &ans) {
    for (auto &dir : dirs) {
        int a = x + dir[0];
        int b = y + dir[1];

        ans += grid[a][b];
    }
}

int maxSum(vector<vector<int>>& grid) {
    int M = grid.size();
    int N = grid[0].size();

    int maxHourGlass = 0;

    for (int i = 1; i < M - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            int ans = grid[i][j];
            dfs(grid, i, j, ans);
            maxHourGlass = max(maxHourGlass, ans);
        }
    }

    return maxHourGlass;
}
};