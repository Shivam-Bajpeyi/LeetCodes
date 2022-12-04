//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int i, int j, int base1, int base2, vector<pair<int, int>> &vec, vector<vector<int>>& grid, 
  vector<vector<int>> &vis){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] != 1 || vis[i][j] ==1)
            return;
        
        vis[i][j] = 1;
        //store shape in set
        vec.push_back({i-base1, j-base2});
        
        //explore all 4 dir
        dfs(i+1, j, base1, base2, vec, grid, vis);      //up
        dfs(i-1, j, base1, base2, vec, grid, vis);      //down
        dfs(i, j+1, base1, base2, vec, grid, vis);      //right
        dfs(i, j-1, base1, base2, vec, grid, vis);      //left
        
  }
  
  int n, m;
    int countDistinctIslands(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        //vis
        vector<vector<int>> vis(n, vector<int>(m, -1));
        
        //to store unique islands
        set<vector<pair<int, int>>> st;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && vis[i][j] != 1){
                    vector<pair<int, int>> vec;
                    dfs(i, j, i, j, vec, grid, vis);
                    st.insert(vec);
                }
                    
            }
        }
        
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends