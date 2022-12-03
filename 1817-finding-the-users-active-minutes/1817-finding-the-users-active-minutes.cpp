class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        //hashmap to count unique times for an id
        unordered_map<int, set<int>> mpp1;
        
        //0->{5, 2}
        for(auto &it: logs){
            mpp1[it[0]].insert(it[1]);
        }
        
        //hashmap to count same size sets-> ids that have same number of timings
        unordered_map<int, int> mpp2;
        for(auto &it: mpp1){
            mpp2[it.second.size()]++;    
        }
        
        //get the ans
        vector<int> ans(k);
        for(auto &it: mpp2){
            ans[it.first-1] = it.second;
        }
        
        return ans;
    }
};