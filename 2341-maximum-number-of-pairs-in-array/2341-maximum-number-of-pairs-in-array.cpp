class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int cnt1 =0;
        
        //hashmap to count pairs
        unordered_map<int, int> mpp;
        for(auto &it: nums){
            mpp[it]++;
            if(mpp[it]==2){
                cnt1++;
                mpp[it]  = 0;
            }
                
        }
        
        //count singles
        int cnt2 = 0;
        for(auto &it: mpp){
            if(it.second==1)
                cnt2++;
        }
        
        return {cnt1, cnt2};
    }
};