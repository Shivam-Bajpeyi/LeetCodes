class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);       //len
        vector<int> cnt(n, 1);      //count
        
        //store LIS for each index
        int maxi = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]> nums[j] && 1+dp[j]==dp[i])  //same dp value increase count
                    cnt[i]+= cnt[j];
                
                //big dp[i] value came
                else if(nums[i]> nums[j] && 1+dp[j] > dp[i]){
                    dp[i] = 1+dp[j];
                    cnt[i] = cnt[j];
                }  
            } 
            maxi = max(maxi, dp[i]);
        }
        
        //take the count value of maxi(length of LIS)
        int ans = 0;
        for(int i=0; i<n; i++){
            if(dp[i]== maxi){
                ans += cnt[i];
            }
        }
        
        return ans;
    }
};