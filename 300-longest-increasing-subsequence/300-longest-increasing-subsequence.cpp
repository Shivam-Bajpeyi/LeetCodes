class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = INT_MIN;
        int n = nums.size();
        vector<int> LIS(n, 1);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]> nums[j] && LIS[i]==LIS[j])
                    LIS[i] = 1+LIS[j];
            }
            
            len = max(len, LIS[i]);
        }
        
        return len;
    }
};