class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        //hashmap to count unique times for an id
        unordered_map<int, set<int>> mpp;
        
        //0->{5, 2}
        for(auto &it: logs){
            mpp[it[0]].insert(it[1]);
        }
        
        //get the ans
        vector<int> ans(k);
        for(auto &it: mpp){
            ans[it.second.size()-1]++;
        }
        
        return ans;
    }
};