class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        
        //store frequencies
        for(auto &it: nums)
            mpp[it]++;
        
        //push frequency with element in pq(freq, element)
        priority_queue<vector<int>> pq;
        for(auto &it: mpp){
            pq.push({it.second, it.first});
        }
        
        //get k frequent elements
        vector<int> ans;
        while(k--){
            auto topp = pq.top();
            pq.pop();
            ans.push_back(topp[1]);
        }
        
        return ans;
    }
};