//step-1: use dp1 to store number of decreasing element and dp2 to store number of increasing elements for that index
//step-2: iterate on index k to n-k-1 to check if i has dp1[i-1]>=k & dp2[i+1]>=k

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        //dp1 & dp2
        vector<int> dec(n+1, 1), inc(n+1, 1);
        
        for(int i=1; i<n; i++)      //dp1 = decreasing
            if(nums[i]<=nums[i-1]) dec[i] = dec[i-1]+1;
        
        for(int i=n-2; i>=0; i--)      //dp2 = increasing
            if(nums[i]<=nums[i+1]) inc[i] = inc[i+1]+1;
        
        vector<int> res;    //store index
        for(int i=k; i<=n-k-1; i++){
            if(dec[i-1]>=k && inc[i+1]>=k)
                res.push_back(i);
        }
    
        return res;
    }
};