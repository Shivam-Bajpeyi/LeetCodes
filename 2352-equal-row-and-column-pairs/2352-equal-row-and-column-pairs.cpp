class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mpp;
        
        //hash every row
        for(auto it: grid)
            mpp[it]++;
        
        //take a colm and see how many pairs it can make 
        int n = grid.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            vector<int> v;
            for(int j=0; j<n; j++){
                v.push_back(grid[j][i]);
                //count pairs
                cnt += mpp[v];
            }
        }
        
        return cnt;
    }
};