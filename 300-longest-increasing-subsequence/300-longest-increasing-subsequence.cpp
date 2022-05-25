class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n, 1);  //every element is a LIS of length 1
        int mx = INT_MIN;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                //ensuring the longest increasing sequence
                if(nums[i]> nums[j] && LIS[i]<= LIS[j])
                    LIS[i] = 1+LIS[j];
            }
            mx = max(mx, LIS[i]);   //update mx
        }
        return mx;
    }
};