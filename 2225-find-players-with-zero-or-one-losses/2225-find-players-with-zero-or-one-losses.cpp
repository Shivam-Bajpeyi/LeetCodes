class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> mpp;
        //hash number of loses for a player
        for(auto &it: matches){
            mpp[it[1]]++;
            if(!mpp.count(it[0]))
                mpp[it[0]] = 0;
        }
        
        
        vector<vector<int>> ans;
        //find answer
        vector<int> ans1, ans2;
        for(auto &it: mpp){
            if(it.second == 0)
                ans1.push_back(it.first);
            if(it.second==1)
                ans2.push_back(it.first);
        }
        
        //push ans[0] = 0 losses, ans[1] = exact 1 loss
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
        
    }
};