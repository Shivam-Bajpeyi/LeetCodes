class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        
        //a%s = b%s
        for(auto &it: nums){
            mpp[it%space]++;
        }
        
        int mn = -1, mx = -1;
        for(auto &it: nums){
            if(mpp[it%space]>mx){
                mx = mpp[it%space];
                mn = it;
            }
            else if(mpp[it%space] == mx){
                mn = min(mn, it);
            }
        }
        
        return mn;
    }
};